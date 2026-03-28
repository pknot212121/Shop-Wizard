#include "command_ui.h"

void CommandUI::run()
{
    showMenu();
    while (true)
    {
        try
        {
            std::cout << LINE_START;
            int choice = getMenuChoice();
            if (choice==11) break;

            std::string id, name,expDate,filename;
            int qty, warranty; double price,thresh;

            std::cout << LINE_START << MENU_OPTIONS[choice];

            switch (choice)
            {
            case 1:
                if (getInputs(id,name,qty,price,warranty))
                    inventory.addItem(makeElectronics(id,name,qty,price,warranty));
                break;
            case 2:
                if (getInputs(id,name,qty,price,expDate))
                    inventory.addItem(makeGrocery(id,name,qty,price,expDate));
                break;
            case 3:
                if (getInputs(id))
                    inventory.removeItem(id);
                break;
            case 4:
                if (getInputs(id,qty))
                    inventory.updateQuantity(id,qty);
                break;
            case 5:
                std::cout << std::endl;
                inventory.displayInventory();
                break;
            case 6:
                if (getInputs(filename))
                    inventory.readFromFile(filename);
                break;
            case 7:
                if (getInputs(filename))
                    inventory.writeToFile(filename);
                break;
            case 8:
                {
                    std::cout << std::endl;
                    auto expensive = findMaxItem(inventory,[](const auto& item){return item->getPrice();});
                    expensive->display();
                }
                break;
            case 9:
                if (getInputs(thresh))
                {
                    std::vector<std::shared_ptr<Item>> found = filterItems(inventory,[thresh](const std::shared_ptr<Item>& item){return item->getQuantity()<thresh;});
                    for (auto& item : found) item->display();
                }
                break;
            case 10:
                std::cout << std::endl;
                sortItems(inventory,
                [](const std::shared_ptr<Item>& item1,const std::shared_ptr<Item>& item2){return item1->getPrice()<item2->getPrice();});
                break;
            default: ;
            }
        } catch (const InventoryException& err) {std::cout << ERR_BASE << err.what() << std::endl;}
    }
}

int CommandUI::getMenuChoice()
{
    int choice = 0;
    getInputs(choice);
    if (choice<1 || choice>11)
        throw InvalidValueException(ERR_OUT_OF_RANGE);
    return choice;
}
