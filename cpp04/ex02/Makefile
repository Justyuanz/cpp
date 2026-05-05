NAME = purevirtual

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++20 -MMD -MP

SRCS = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp
HEADERS = AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp
OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
