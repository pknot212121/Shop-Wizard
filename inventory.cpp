//
// Created by tk2 on 3/26/26.
//

#include "inventory.h"

#include <algorithm>

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
