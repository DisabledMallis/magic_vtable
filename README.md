# Magic VTable
A small C++23 library to acquire vtable information at compile time


## Usage
Get a vtable function index at compile time
```
constexpr auto index = magic_vft::vtable_index<&TestClass::c>();
std::cout << index.value() << std::endl;
```
or at runtime
```
std::cout << magic_vft::vtable_index<&TestClass::b>().value() << std::endl;
```