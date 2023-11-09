#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(const Brain& original);
		const Brain& operator=(const Brain& original);
		virtual ~Brain(void);

		virtual const std::string& getIdea(const int& index) const;
		void setIdea(const std::string& idea, const int& index);
};
#endif
