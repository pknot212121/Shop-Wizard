//
// Created by tk2 on 3/26/26.
//

#include "inventory.h"

#include <algorithm>

#include "electronics.h"
#include "grocery.h"

void Inventory::addItem(std::shared_ptr<Item> item)
{
    items.push_back(item);
}

void Inventory::removeItem(const std::string& itemID)
{
    auto it = std::remove_if(items.begin(),items.end(),
        [&itemID](const std::shared_ptr<Item>& item){return item->getItemID()==itemID;});
    items.erase(it,items.end());
}

void Inventory::updateQuantity(const std::string& itemID, int quantity)
{
    for (auto& item : items)
        if (item->getItemID()==itemID)
            item->setQuantity(quantity);
}

void Inventory::displayInventory() const
{
    for (auto& item : items)
        item->display();
}
