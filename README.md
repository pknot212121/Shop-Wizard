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