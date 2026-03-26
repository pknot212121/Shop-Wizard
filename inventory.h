#ifndef SHOP_WIZARD_INVENTORY_H
#define SHOP_WIZARD_INVENTORY_H
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

    static std::shared_ptr<Item> makeElectronics(const std::string& id, const std::string& name,
        int qty,double price, int warrantyMonths)
    {
        return std::make_shared<Electronics>(id,name,qty,price,warrantyMonths);
    }
    static std::shared_ptr<Item> makeGrocery(const std::string& id, const std::string& name,
        int qty, double price, const std::string& expDate)
    {
        return std::make_shared<Grocery>(id,name,qty,price,expDate);
    }

    template<typename Predicate>
    std::vector<std::shared_ptr<Item>> filterItems(const Inventory& inv, Predicate pred);
    template<typename Key>
    void sortItems(Inventory& inv, Key keyFn);
private:
    std::vector<std::shared_ptr<Item>> items;
};


#endif //SHOP_WIZARD_INVENTORY_H