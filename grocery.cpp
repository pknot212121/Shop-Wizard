//
// Created by tk2 on 3/26/26.
//

#include "grocery.h"

#include <iostream>

void Grocery::display() const
{
    std::cout << "[Grocery]     ID: " << this->getItemID()
    << " | Name: " << this->getName() << " | Qty: " << this->getQuantity()
    << " | Price: " << this->getPrice() << " | Warranty: " << expirationDate << std::endl;
}

std::optional<std::string> Grocery::findAttribute(const std::string& key) const
{
    if (key==EXPIRATION_KEY)
        return expirationDate;
    return std::nullopt;
}
