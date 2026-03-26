

#ifndef SHOP_WIZARD_ELECTRONICS_H
#define SHOP_WIZARD_ELECTRONICS_H
#include "item.h"
#include <iostream>

class Electronics : public Item
{
public:
    static constexpr const char* CATEGORY_NAME = "Electronics";
    static constexpr const char* WARRANTY_KEY = "warranty";
    Electronics(std::string id, std::string n, int q, double p, int w)
        : Item(std::move(id),std::move(n),q,p), warrantyMonths(w) {}
    void display() const noexcept override;
    std::string category() const noexcept override {return CATEGORY_NAME;}
    std::optional<std::string> findAttribute(const std::string& key) const noexcept override;
    ~Electronics() override = default;
private:
    int warrantyMonths = 0;
};


#endif //SHOP_WIZARD_ELECTRONICS_H
