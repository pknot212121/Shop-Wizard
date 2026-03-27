
#ifndef SHOP_WIZARD_ITEM_H
#define SHOP_WIZARD_ITEM_H
#include <optional>
#include <string>
#include <utility>
#include <string_view>
#include "exceptions.h"

static constexpr const char* PRICE_NEGATIVE_ERR = "Price cannot be negative!";
static constexpr const char* QUANT_NEGATIVE_ERR = "Quantity cannot be negative!";

class Item
{
public:
    Item(std::string id,std::string n,int q,double p) : itemID(std::move(id)), name(std::move(n)), quantity(q), price(p)
    {if (p<0) throw InvalidValueException(PRICE_NEGATIVE_ERR); if (q<0) throw InvalidValueException(QUANT_NEGATIVE_ERR);}

    virtual void display() const noexcept = 0;
    virtual std::string category() const noexcept = 0;
    virtual std::optional<std::string> findAttribute(const std::string& key) const noexcept = 0;
    virtual ~Item() noexcept = default;

    std::string getItemID() const noexcept {return itemID;}
    std::string getName() const noexcept {return name;}
    int getQuantity() const noexcept {return quantity;}
    double getPrice() const noexcept {return price;}



    void setItemID(std::string id) noexcept {itemID=std::move(id);}
    void setName(std::string n) noexcept {name=std::move(n);}
    void setQuantity(int q){q>=0 ? quantity=q : throw InvalidValueException(QUANT_NEGATIVE_ERR);}
    void setPrice(double p){p>=0 ? price=p : throw InvalidValueException(PRICE_NEGATIVE_ERR);}
private:
    std::string itemID;
    std::string name;
    int quantity = 0;
    double price = 0;
};


#endif