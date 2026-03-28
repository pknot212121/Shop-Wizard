#include "grocery.h"

#include <iostream>

void Grocery::display() const noexcept
{
    std::cout << std::left
    << std::setw(DisplayConfig::W_CAT) << DisplayConfig::L_GR
    << DisplayConfig::L_ID << std::setw(DisplayConfig::W_ID) << this->getItemID()
    << DisplayConfig::L_NAME << std::setw(DisplayConfig::W_NAME) << this->getName()
    << DisplayConfig::L_QTY << std::right << std::setw(DisplayConfig::W_QTY) << this->getQuantity()
    << DisplayConfig::L_PRICE << std::fixed << std::setprecision(2) << std::setw(DisplayConfig::W_PRICE) << this->getPrice()
    << DisplayConfig::L_EXPIRES << expirationDate << std::endl;
}

std::optional<std::string> Grocery::findAttribute(const std::string& key) const noexcept
{
    if (key==EXPIRATION_KEY)
        return expirationDate;
    return std::nullopt;
}
