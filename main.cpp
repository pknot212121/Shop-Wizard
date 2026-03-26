#include <iostream>
#include "electronics.h"
#include "grocery.h"
#include "inventory.h"
int main()
{

  /* ----TASK 1-----*/

  Electronics e("E1","Phone",10,699.99,24);
  e.display();
  Grocery g("G1","Apple",30,1.49,"2026-06-01");
  g.display();
  std::cout << e.category() << " " << g.category() << std::endl;
  std::cout << e.findAttribute("warranty").value_or("Brak") << " "
  << e.findAttribute("expirationDate").value_or("Brak") << std::endl;
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

  i2.addItem(Inventory::makeElectronics("E1","Phone",10,699.99,24));
  i2.addItem(Inventory::makeGrocery("G1","Apple",30,1.49,"2026-06-01"));

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
}
