#include <iostream>
#include "electronics.h"
#include "grocery.h"

int main()
{
  Electronics e("E1","Phone",10,699.99,24);
  e.display();
  Grocery g("G1","Apple",30,1.49,"2026-06-01");
  g.display();
  std::cout << e.category() << " " << g.category() << std::endl;
  std::cout << e.findAttribute("warranty").value_or("Brak") << " "
  << e.findAttribute("expirationDate").value_or("Brak") << std::endl;
}
