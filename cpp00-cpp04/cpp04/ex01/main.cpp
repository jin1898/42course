#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void a(void)
{
	system("leaks -q ex00");
}

int main()
{
	//--subject main--start
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	//--subject main--end

	const WrongAnimal	*k = new WrongCat();
	const WrongAnimal	*l = new WrongAnimal();
	k->makeSound();
	l->makeSound();
	delete k;
	delete meta;
	delete i;
	delete j;
	delete l;

	atexit(a);

	return 0;
}
