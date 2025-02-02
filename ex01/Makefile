COMPILER = c++
NAME_TARGET = phonebook
NAME_TEST = test
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c -std=c++98
LINK_FLAGS = 
PREFIX = 

SRC_NAMES = PhoneBook.cpp Contact.cpp

SRC_OBJS = $(SRC_NAMES:.cpp=.o)

all: $(NAME_TARGET)

$(NAME_TARGET): $(SRC_OBJS)
	$(PREFIX)$(COMPILER) $(SRC_OBJS) -o $(NAME_TARGET) $(LINK_FLAGS)

%.o: %.cpp
	$(PREFIX)$(COMPILER) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(PREPROC_DEFINES)

clean:
	$(PREFIX)rm -f $(SRC_OBJS) $(TEST_OBJS)

fclean: clean
	$(PREFIX)rm -f $(NAME_TARGET) $(NAME_TEST)

test:
	$(PREFIX)rm -f out.txt err.txt
	$(PREFIX)make all clean test
	$(PREFIX)./$(NAME_TEST)
	$(PREFIX)rm -f out.txt err.txt

re: fclean all

retest: fclean test

PHONY: all pre clean fclean re test