# Magic VTable
A small C++23 library to acquire vtable information at compile time


## Usage
Get a vtable function index at compile time
```
constexpr auto index = cvft::get_virtual_index<&TestClass::c>();
std::cout << index.value() << std::endl;
```
or at runtime
```
std::cout << cvft::get_virtual_index<&TestClass::b>().value() << std::endl;
```