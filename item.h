
#ifndef SHOP_WIZARD_ITEM_H
#define SHOP_WIZARD_ITEM_H
#include <string>


class Item
{
public:
    virtual void display() const = 0;
    virtual std::string category() const = 0;
    virtual ~Item() = default;

    std::string getItemID(){return itemID;}
    std::string getName(){return name;}
    int getQuantity(){return quantity;}
    double getPrice(){return price;}

    void setItemID(const std::string& id){itemID=id;}
    void setName(const std::string& n){name=n;}
    void setQuantity(int q){quantity=q;}
    void setPrice(double p){price=p;}
private:
    std::string itemID;
    std::string name;
    int quantity = 0;
    double price = 0;
};


#endif