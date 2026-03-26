

#ifndef SHOP_WIZARD_ELECTRONICS_H
#define SHOP_WIZARD_ELECTRONICS_H
#include "item.h"


class Electronics : public Item
{
public:
    void display() const override;
    std::string category() const override;
private:
    int warrantyMonths = 0;
};


#endif //SHOP_WIZARD_ELECTRONICS_H