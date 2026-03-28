#include <iostream>

#include "command_ui.h"
#include "electronics.h"
#include "grocery.h"
#include "inventory.h"

void runTests()
{
  /* ----TASK 1-----*/

  Electronics e("E1","Phone",10,699.99,24);
  e.display();
  Grocery g("G1","Apple",30,1.49,"2026-06-01");
  g.display();
  std::cout << e.category() << " " << g.category() << std::endl;
  std::cout << e.findAttribute("warranty").value_or("None") << " "
  << e.findAttribute("expirationDate").value_or("None") << std::endl;
  std::cout << "--------------------------------------------------" << std::endl;

  /* ----TASK 2-----*/

  Inventory i;
  i.addItem(std::make_shared<Electronics>("E1","Phone",10,699.99,24));
  i.addItem(std::make_shared<Grocery>("G1","Apple",30,1.49,"2026-06-01"));
  i.displayInventory();
  i.updateQuantity("G1",100);
  i.displayInventory();
  i.removeItem("E1");
  i.displayInventory();
  std::cout << "--------------------------------------------------" << std::endl;

  /* ----TASK 3-----*/

  Inventory i2,i3;

  i2.addItem(makeElectronics("E1","Phone",10,699.99,24));
  i2.addItem(makeGrocery("G1","Apple",30,1.49,"2026-06-01"));

  std::cout << "BEFORE MOVE" << std::endl;
  std::cout << "Displaying i2:" << std::endl;
  i2.displayInventory();
  std::cout << "Displaying i3:" << std::endl;
  i3.displayInventory();

  std::cout << "AFTER MOVE" << std::endl;
  i3 = std::move(i2);
  std::cout << "Displaying i2:" << std::endl;
  i2.displayInventory();
  std::cout << "Displaying i3:" << std::endl;
  i3.displayInventory();
  std::cout << "--------------------------------------------------" << std::endl;


  /* ----TASK 4-----*/

  Inventory i4;
  i4.addItem(makeElectronics("E1","Phone",10,699.99,24));
  i4.addItem(makeGrocery("G1","Apple",30,1.49,"2026-06-01"));
  i4.addItem(makeGrocery("P1","Potato",30,16.49,"2026-06-01"));
  i4.addItem(makeElectronics("L1","Laptop",10,1799.99,24));
  auto a = filterItems(i4,[](const std::shared_ptr<Item>& item){return item->getQuantity()<20;});
  for (auto& item : a ) item->display();

  std::cout << "BEFORE SORTING: " << std::endl;
  i4.displayInventory();

  sortItems(i4,[](const std::shared_ptr<Item>& item1,const std::shared_ptr<Item>& item2){return item1->getPrice()<item2->getPrice();});
  std::cout << "AFTER SORTING: " << std::endl;
  i4.displayInventory();
  std::cout << "--------------------------------------------------" << std::endl;

  /* ----TASK 5-----*/

  Inventory i5;
  i5.addItem(makeElectronics("E1","Phone",10,699.99,24));
  try
  {
    i5.addItem(makeElectronics("E1","Phone2",10,699.99,24));
    i5.removeItem("00");
  } catch (const InventoryException& err)
  {
    std::cout << "Error: " << err.what() << std::endl;
  }

  try
  {
    i5.removeItem("00");
  } catch (const InventoryException& err)
  {
    std::cout << "Error: " << err.what() << std::endl;
  }

  try
  {
    i5.updateQuantity("99",100);
  } catch (const InventoryException& err)
  {
    std::cout << "Error: " << err.what() << std::endl;
  }

  try
  {
    i5.updateQuantity("E1",-177);
  } catch (const InventoryException& err)
  {
    std::cout << "Error: " << err.what() << std::endl;
  }

  std::cout << "--------------------------------------------------" << std::endl;

  /* ----TASK 6----- */

  Inventory i6;
  i6.readFromFile("inventory.csv");
  i6.displayInventory();

  try
  {
    i6.readFromFile("bbbbbwkdw.csv");
  } catch (const InventoryException& err)
  {
    std::cout << "Error: " << err.what() << std::endl;
  }

  try
  {
    i6.writeToFile("inventorySaved.csv");
  } catch (const InventoryException& err)
  {
    std::cout << "Error: " << err.what() << std::endl;
  }
  std::cout << "--------------------------------------------------" << std::endl;
}

int main()
{
  runTests();

  CommandUI app;
  app.run();

}
