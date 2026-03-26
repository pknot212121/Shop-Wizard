#ifndef SHOP_WIZARD_GROCERY_H
#define SHOP_WIZARD_GROCERY_H
#include <string>

#include "item.h"


class Grocery : public Item
{
public:
    static constexpr const char* CATEGORY_NAME = "Grocery";
    static constexpr const char* EXPIRATION_KEY = "expirationDate";
    Grocery(std::string id, std::string n, int q, double p, std::string e)
        : Item(std::move(id),std::move(n),q,p),expirationDate(std::move(e)) {}
    void display() const override;
    std::string category() const override {return CATEGORY_NAME;}
    std::optional<std::string> findAttribute(const std::string& key) const override;
    ~Grocery() override = default;
private:
    std::string expirationDate;
};


#endif //SHOP_WIZARD_GROCERY_H