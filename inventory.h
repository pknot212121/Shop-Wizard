#ifndef SHOP_WIZARD_INVENTORY_H
#define SHOP_WIZARD_INVENTORY_H
#include <memory>
#include <vector>

#include "item.h"


class Inventory
{
public:
    void addItem(std::shared_ptr<Item>);
    void removeItem(const std::string& itemID);
    void updateQuantity(const std::string& itemID, int quantity);
    void displayInventory() const;

    std::shared_ptr<Item> makeElectronics(const std::string& id, const std::string& name,
        int qty,double price, int warrantyMonths);
    std::shared_ptr<Item> makeGrocery(const std::string& id, const std::string& name,
        int qty, double price, const std::string& expDate);
private:
    std::vector<std::shared_ptr<Item>> items;
};


#endif //SHOP_WIZARD_INVENTORY_H