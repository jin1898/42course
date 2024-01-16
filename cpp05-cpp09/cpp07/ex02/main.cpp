#include "Array.hpp"

template <typename T>
void printArry(Array<T> &arr){
	for(unsigned int i = 0; i < arr.getSize(); i++)
		std::cout << arr[i] << ", ";
	std::cout << std::endl;
}

int main(void)
{
	Array<int> ary(3);
	for(int i = 0; i < 3; i++)
		ary[i] = i;
	std::cout << std::endl;
	printArry(ary);


	Array<char> ary2(3);
	for(int i = 0; i < 3; i++)
		ary2[i] = i + 65;
	std::cout << std::endl;
	printArry(ary2);

	Array<int> ary3;
	printArry(ary3);
	ary3 = ary;
	printArry(ary3);
	ary3[0] = 455;
	printArry(ary3);
	printArry(ary);
	try{
		ary3[15] = 1;
	}
	catch(std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}
}