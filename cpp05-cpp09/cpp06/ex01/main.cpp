#include "./Serializer.hpp"

void printData(Data* data) {
	std::cout << "-start---------" << "\n";
	std::cout << "Data:" << std::endl;
	std::cout << "Str: " << data->s1 << std::endl;
	std::cout << "Int: " << data->n << std::endl;
	std::cout << "Ptr: " << data << std::endl;
	std::cout << "------------end-" << "\n";
}

int main(void) {
	Data* data = new Data;
	data->s1 = "gogo 42";
	data->n = 42;

	printData(data);

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "UIP: " << raw << std::endl;
	Data* data2 = Serializer::deserialize(raw);

	printData(data2);

	delete data;
	return 0;
}
