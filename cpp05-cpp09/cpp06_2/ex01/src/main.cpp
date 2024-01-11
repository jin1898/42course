#include "../include/Serializer.hpp"

void printData(Data* data) {
	int padding = data->s1.size()/2 + 5 > 10 ? data->s1.size()/2 + 5 : 10;
	std::cout << B << std::setw(padding) << "Data:" << std::setw(padding) << C << std::endl;
	std::cout << "Str: " DV << data->s1 << C << std::endl;
	std::cout << "Int: " DV << data->n << C << std::endl;
	std::cout << "Ptr: " DV << data << C << std::endl;
}

int main(void) {
	Data* data = new Data;
	data->s1 = "Hello World!";
	data->n = 19;

	printData(data);

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "UIP: " DV << raw << std::endl;
	Data* data2 = Serializer::deserialize(raw);

	printData(data2);

	delete data;
	return 0;
}