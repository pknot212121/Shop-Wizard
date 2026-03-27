#ifndef SHOP_WIZARD_COMMAND_UI_H
#define SHOP_WIZARD_COMMAND_UI_H
#include "inventory.h"
#include <iostream>
#include <sstream>

static constexpr const char* MENU_OPTIONS[12] = {
    "",
    "Add Electronics: ",
    "Add Grocery: ",
    "Remove Item: ",
    "Update Quantity: ",
    "Display Inventory: ",
    "Read from File: ",
    "Write to File: ",
    "Find Most Expensive Item: ",
    "Find Items Below Quantity Threshold: ",
    "Sort by Price: ",
    "Exiting"
};

static constexpr const char* MENU =
    "Welcome to Shop wizard!\nChoose one of the following options:\n1. Add Electronics\n2. Add Grocery\n3. Remove Item\n4. Update Quantity\n5. Display Inventory\n6. Read from File\n7. Write to File\n8. Find Most Expensive Item\n9. Find Items Below Quantity Threshold\n10. Sort by Price\n11. Exit ";

static constexpr const char* ERR_INVALID_ARGS = "Not enough arguments or bad argument types!";
static constexpr const char* ERR_TOO_MANY_ARGS = "Too many arguments!";
static constexpr const char* ERR_NOT_NUMBER = "Input must be a number!";
static constexpr const char* ERR_OUT_OF_RANGE = "Option out of range (1-11)!";

class CommandUI {
public:
    void run();
private:
    void showMenu() noexcept {std::cout << MENU << std::endl;};
    int getMenuChoice();
    Inventory inventory;
};

template<typename... Args>
bool getInputs(Args&... args)
{
    std::string line;
    if (!std::getline(std::cin >> std::ws, line)) return false;
    std::stringstream ss(line);
    if (!(ss >> ... >> args))
        throw InvalidValueException(ERR_INVALID_ARGS);
    std::string extra;
    if (ss>>extra)
        throw InvalidValueException(ERR_TOO_MANY_ARGS);
    return true;
}



#endif //SHOP_WIZARD_COMMAND_UI_H
