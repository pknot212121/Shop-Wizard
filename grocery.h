#ifndef SHOP_WIZARD_GROCERY_H
#define SHOP_WIZARD_GROCERY_H
#include <string>

#include "item.h"


class Grocery : public Item
{
public:
    void display() const override;
    std::string category() const override;
private:
    std::string expirationDate;
};


#endif //SHOP_WIZARD_GROCERY_H