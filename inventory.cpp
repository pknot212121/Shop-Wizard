//
// Created by tk2 on 3/26/26.
//

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

    std::string line;
    while (std::getline(file,line))
    {
        std::stringstream ss(line);
        std::string id,cat,name,qnyStr,priceStr,extra;

        std::getline(ss,id,','); std::getline(ss,cat,',');
        std::getline(ss,name,','); std::getline(ss,qnyStr,',');
        std::getline(ss,priceStr,','); std::getline(ss,extra,',');

        int qty = std::stoi(qnyStr);
        double price = std::stod(priceStr);
        if (qty<0) throw InvalidValueException(qty);
        if (price<0) throw InvalidValueException(price);
        if (cat==Electronics::CATEGORY_NAME)
            addItem(makeElectronics(id,name,qty,price,std::stoi(extra)));
        else if (cat==Grocery::CATEGORY_NAME)
            addItem(makeGrocery(id,name,qty,price,extra));
        else throw InventoryException("Category: " + cat + " not available!");
    }
}

void Inventory::writeToFile(const std::string& filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
        throw InventoryException("File cannot be opened to save!");
    for (const auto& item : items)
    {
        file << item->getItemID() << "," << item->category() << ","
        << item->getName() << "," << item->getQuantity() << ","
        << item->getPrice();

        if (item->category()==Electronics::CATEGORY_NAME)
            file << "," << item->findAttribute(Electronics::WARRANTY_KEY).value_or("0");
        else file << "," << item->findAttribute(Grocery::EXPIRATION_KEY).value_or("N/A");
        file << "\n";
    }
}
