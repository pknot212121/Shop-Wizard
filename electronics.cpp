//
// Created by tk2 on 3/26/26.
//

#include "electronics.h"

void Electronics::display() const noexcept
{
    std::cout << "[Electronics] ID: " << this->getItemID()
    << " | Name: " << this->getName() << " | Qty: " << this->getQuantity()
    << " | Price: " << this->getPrice() << " | Warranty: " << warrantyMonths
    << " months" << std::endl;
}

std::optional<std::string> Electronics::findAttribute(const std::string& key) const noexcept
{
    if (key==WARRANTY_KEY)
        return std::to_string(warrantyMonths);
    return std::nullopt;
}
