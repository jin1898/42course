#include "./Serializer.hpp"

Serializer::Serializer(void) {std::cout << "[OCCF] 사용불가" << std::endl;}

Serializer::Serializer(Serializer const & src) {
	std::cout << "[OCCF] 사용불가" << std::endl;
	*this = src;
}

Serializer::~Serializer(void) {std::cout << "[OCCF] 사용불가" << std::endl;}

Serializer & Serializer::operator=(Serializer const & rhs) {
	std::cout << "[OCCF] 사용불가" << std::endl;
	(void)rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
