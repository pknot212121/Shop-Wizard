#ifndef SHOP_WIZARD_INVENTORYEXCEPTIONS_H
#define SHOP_WIZARD_INVENTORYEXCEPTIONS_H
#include <stdexcept>

class InventoryException : public std::runtime_error
{
public:
    explicit InventoryException(const std::string& msg) : std::runtime_error(msg) {}
};

class ItemNotFoundException : public InventoryException
{
public:
    explicit ItemNotFoundException(const std::string& id)
        : InventoryException("Item not found with ID: " + id) {}
};

class DuplicateItemException : public InventoryException
{
public:
    explicit DuplicateItemException(const std::string& id)
        : InventoryException("Item with ID: " + id + " already exists!") {}
};

class InvalidValueException : public InventoryException
{
public:
    explicit InvalidValueException(int val)
        : InventoryException("Value: " + std::to_string(val) + " is not correct / negative!") {}
};

#endif //SHOP_WIZARD_INVENTORYEXCEPTIONS_H