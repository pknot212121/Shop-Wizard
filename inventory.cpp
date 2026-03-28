#include "inventory.h"

#include <algorithm>
#include <sstream>

#include "electronics.h"
#include "grocery.h"

void Inventory::addItem(std::shared_ptr<Item> item)
{
    for (auto& a : items)
        if (a->getItemID()==item->getItemID())
            throw DuplicateItemException(a->getItemID());
    items.push_back(item);
}

void Inventory::removeItem(const std::string& itemID)
{
    auto it = std::remove_if(items.begin(),items.end(),
        [&itemID](const std::shared_ptr<Item>& item){return item->getItemID()==itemID;});
    if (it == items.end())
        throw ItemNotFoundException(itemID);

    items.erase(it,items.end());
}

void Inventory::updateQuantity(const std::string& itemID, int quantity)
{
    bool found = false;
    for (auto& item : items)
        if (item->getItemID()==itemID)
        {
            item->setQuantity(quantity);
            found = true;
        }
    if (!found)
        throw ItemNotFoundException(itemID);
}

void Inventory::displayInventory() const noexcept
{
    for (auto& item : items)
        item->display();
}

void Inventory::readFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw InventoryException("File " + filename + " not found!");

    Inventory tempInventory;
    std::string line;
    while (std::getline(file,line))
    {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string id,cat,name,qnyStr,priceStr,extra;

        if (!std::getline(ss,id,',') || !std::getline(ss,cat,',') ||
        !std::getline(ss,name,',') || !std::getline(ss,qnyStr,',') ||
        !std::getline(ss,priceStr,',') || !std::getline(ss,extra,','))
        {
            throw InventoryException("Invalid file format in line: " + line);
        }
        std::string trailing;
        if (ss >> trailing) throw InventoryException("Too many columns in line: " + line);
        try
        {
            int qty = std::stoi(qnyStr);
            double price = std::stod(priceStr);
            if (qty<0) throw InvalidValueException(QUANT_NEGATIVE_ERR);
            if (price<0) throw InvalidValueException(PRICE_NEGATIVE_ERR);
            if (cat==Electronics::CATEGORY_NAME)
                tempInventory.addItem(makeElectronics(id,name,qty,price,std::stoi(extra)));
            else if (cat==Grocery::CATEGORY_NAME)
                tempInventory.addItem(makeGrocery(id,name,qty,price,extra));
            else throw InventoryException("Category: " + cat + " not available!");
        } catch (const std::invalid_argument&)
        {
            throw InvalidValueException("Numeric conversion failed in line: " + line);
        } catch (const std::out_of_range&)
        {
            throw InvalidValueException("Numeric conversion failed: (invalid format or value too large) in line: " +line);
        }

    }
    *this = std::move(tempInventory);
}

void Inventory::writeToFile(const std::string& filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
        throw InventoryException(ERR_SAVE_FAIL);
    for (const auto& item : items)
    {
        file << item->getItemID() << ',' << item->category() << ','
        << item->getName() << ',' << item->getQuantity() << ','
        << item->getPrice();

        if (item->category()==Electronics::CATEGORY_NAME)
            file << ',' << item->findAttribute(Electronics::WARRANTY_KEY).value_or("0");
        else file << ',' << item->findAttribute(Grocery::EXPIRATION_KEY).value_or("N/A");
        file << '\n';
    }
}
