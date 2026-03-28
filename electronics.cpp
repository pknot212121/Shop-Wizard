#include "electronics.h"

void Electronics::display() const noexcept
{
    std::cout << std::left
    << std::setw(DisplayConfig::W_CAT) << DisplayConfig::L_EL
    << DisplayConfig::L_ID << std::setw(DisplayConfig::W_ID) << this->getItemID()
    << DisplayConfig::L_NAME << std::setw(DisplayConfig::W_NAME) << this->getName()
    << DisplayConfig::L_QTY << std::right << std::setw(DisplayConfig::W_QTY) << this->getQuantity()
    << DisplayConfig::L_PRICE << std::fixed << std::setprecision(2) << std::setw(DisplayConfig::W_PRICE) << this->getPrice()
    << DisplayConfig::L_WARRANTY << warrantyMonths << DisplayConfig::L_MONTHS << std::endl;
}

std::optional<std::string> Electronics::findAttribute(const std::string& key) const noexcept
{
    if (key==WARRANTY_KEY)
        return std::to_string(warrantyMonths);
    return std::nullopt;
}
