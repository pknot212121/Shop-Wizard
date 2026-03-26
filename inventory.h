#ifndef SHOP_WIZARD_INVENTORY_H
#define SHOP_WIZARD_INVENTORY_H
#include <algorithm>
#include <memory>
#include <vector>

#include "electronics.h"
#include "grocery.h"
#include "item.h"


class Inventory
{
public:
    Inventory() = default;

    Inventory(const Inventory&) = delete;
    Inventory operator=(const Inventory&) = delete;

    Inventory(Inventory&&) noexcept = default;
    Inventory& operator=(Inventory&&) noexcept = default;

    void addItem(std::shared_ptr<Item>);
    void removeItem(const std::string& itemID);
    void updateQuantity(const std::string& itemID, int quantity);
    void displayInventory() const;

    const auto& getItems() const {return items;}
    auto& getItemsMutable()  {return items;}
private:
    std::vector<std::shared_ptr<Item>> items;
};

inline std::shared_ptr<Item> makeElectronics(const std::string& id, const std::string& name,
                                             int qty,double price, int warrantyMonths)
{
    return std::make_shared<Electronics>(id,name,qty,price,warrantyMonths);
}

inline std::shared_ptr<Item> makeGrocery(const std::string& id, const std::string& name,
                                         int qty, double price, const std::string& expDate)
{
    return std::make_shared<Grocery>(id,name,qty,price,expDate);
}

template <typename Predicate>
std::vector<std::shared_ptr<Item>> filterItems(const Inventory& inv, Predicate pred)
{
    std::vector<std::shared_ptr<Item>> result;
    auto& items = inv.getItems();
    std::copy_if(items.begin(),items.end(),std::back_inserter(result),pred);
    return result;
}

template<typename Key>
void sortItems(Inventory& inv, Key keyFn)
{
    auto& items = inv.getItemsMutable();
    std::sort(items.begin(),items.end(),keyFn);
}

#endif //SHOP_WIZARD_INVENTORY_H
