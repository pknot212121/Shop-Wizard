
#ifndef SHOP_WIZARD_ITEM_H
#define SHOP_WIZARD_ITEM_H
#include <optional>
#include <string>
#include <utility>


class Item
{
public:
    Item(std::string id,std::string n,int q,double p) : itemID(std::move(id)), name(std::move(n)), quantity(q), price(p){}

    virtual void display() const = 0;
    virtual std::string category() const = 0;
    virtual std::optional<std::string> findAttribute(const std::string& key) const = 0;
    virtual ~Item() = default;

    std::string getItemID() const {return itemID;}
    std::string getName() const {return name;}
    int getQuantity() const {return quantity;}
    double getPrice() const {return price;}



    void setItemID(std::string id){itemID=std::move(id);}
    void setName(std::string n){name=std::move(n);}
    void setQuantity(int q){quantity=q;}
    void setPrice(double p){price=p;}
private:
    std::string itemID;
    std::string name;
    int quantity = 0;
    double price = 0;
};


#endif