# ifndef CAT_HPP
#define CAT_HPP

#include"AAnimal.hpp"
#include"Brain.hpp"
class Cat : public AAnimal
{
	private:
	Brain *_brain;
	public:
	Cat();
	~Cat();

	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	void makeSound() const;
	void setIdea(int i, const std::string &s);
	const std::string &getIdea(int i) const;
};
#endif
