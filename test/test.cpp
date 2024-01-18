#include <constexpr_vtable.hpp>

#include <iostream>

struct TestClass
{
	virtual void a() = 0;
	virtual void b() = 0;
	virtual void c() = 0;
};

int main()
{
	//Find the index at compile time
	constexpr auto index = cvft::get_virtual_index<&TestClass::c>();
	std::cout << index.value() << std::endl;

	//Retrieve the index at runtime
	std::cout << cvft::get_virtual_index<&TestClass::b>().value() << std::endl;
}