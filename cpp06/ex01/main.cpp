#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;

	data.name = "Yuan";
	data.age = 30;
	data.score = 98.5;

	Data* originalPtr = &data;

    std::cout << "originalPtr: " << originalPtr << std::endl;

    uintptr_t raw = Serializer::serialize(originalPtr);

    std::cout << "raw: " << raw << std::endl;
    if (raw % 8 == 0)
	    std::cout << "8-byte aligned" << std::endl;
    else
	    std::cout << "not aligned" << std::endl;

	Data* restoredPtr = Serializer::deserialize(raw);

	if (originalPtr == restoredPtr)
		std::cout << "SUCCESS: originalPtr == restoredPtr" << std::endl;
	else
		std::cout << "ERROR: originalPtr != restoredPtr" << std::endl;

	return (0);
}