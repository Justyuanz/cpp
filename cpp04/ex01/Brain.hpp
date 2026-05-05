# ifndef BRAIN_HPP
#define BRAIN_HPP

#include<string>

class Brain
{
	private:
	std::string	_ideas[100]; //The array already contains 100 std::string objects, can assign into them directly with _ideas[i] = s;

	public:
	Brain();
	~Brain();

	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	void setIdea(int i, const std::string &s);
	const std::string &getIdea(int i) const;
};

#endif
