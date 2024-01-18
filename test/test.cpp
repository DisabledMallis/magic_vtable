#include <magic_vtable.hpp>

#include <iostream>

struct TestClass
{
	virtual void a() = 0;
	virtual void b() = 0;
	virtual void c() = 0;

	void non_virtual() {}
};

static_assert(magic_vft::vtable_index<&TestClass::a>() == 0);
static_assert(magic_vft::vtable_index<&TestClass::b>() == 1);
static_assert(magic_vft::vtable_index<&TestClass::c>() == 2);

int main()
{
	// Find the index at compile time
	constexpr auto index = magic_vft::vtable_index<&TestClass::c>();
	std::cout << index << std::endl;

	// Retrieve the index at runtime
	std::cout << magic_vft::vtable_index<&TestClass::b>() << std::endl;
}