#pragma once

#include<cstdint>
#include"Data.hpp"
class  Serializer
{
private:
	 Serializer() = delete;
	 Serializer(const Serializer &other) = delete;
	 ~Serializer() = delete;

	 Serializer &operator=(const Serializer &other) = delete;
public:
	static uintptr_t serialize(Data* ptr); //an integer big enough to hold a memory address
	static Data* deserialize(uintptr_t raw);
};