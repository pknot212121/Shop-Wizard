# Shop Wizard - Inventory Management System

### How to use
The commands should be inputted as follows:
```
> 1
> Add Electronics: E1 Phone 10 699.99 24
> 
```
- The arguments should be separated by spaces
- Only the exact number and type of arguments can be inputted, otherwise the program will throw an exception.

### Tests
- The program also includes some test and sample .csv files for earlier tasks.

### Requirements
- **C++ Compiler:** A compiler with C++17 support is required
- **CMake:** 3.10 or newer

### How to run
- With CMake
```
mkdir build
cd build

cmake ..
cmake --build .
./Shop_Wizard
```
- Without CMake (On Linux / macOS)
```
g++ -std=c++17 main.cpp electronics.cpp grocery.cpp inventory.cpp command_ui.cpp -o Shop_Wizard
./Shop_Wizard
```

### Commands
The available commands are:
1. Add Electronics - params: (string id,string name,int qty,double price,int warranty)
2. Add Grocery - params: (string id,string name,int qty,double price,string exp)
3. Remove Item - params: (string id)
4. Update Quantity - params: (string id,int qty)
5. Display Inventory
6. Read from File - params: (string filename)
7. Write to File - params: (string filename)
8. Find Most Expensive Item
9. Find Items Below Quantity Threshold - params: (int qty)
10. Sort by Price
11. Exit 