#include <magic_vtable.hpp>

#include <iostream>

struct TestClass
{
	virtual void a() = 0;
	virtual void b() = 0;
	virtual void c() = 0;

	void non_virtual() {}
};

int main()
{
	//Find the index at compile time
	constexpr auto index = magic_vft::vtable_index<&TestClass::c>();
	std::cout << index.value() << std::endl;

	//Retrieve the index at runtime
	std::cout << magic_vft::vtable_index<&TestClass::b>().value() << std::endl;
}