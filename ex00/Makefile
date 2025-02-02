COMPILER = c++
NAME_TARGET = megaphone
NAME_TEST = test
NAME_CURRENT = $(NAME_TARGET)
COMPILE_FLAGS = -Wall -Wextra -Werror -g -c -std=c++98
LINK_FLAGS = 
PREFIX = 
PREPROC_DEFINES = 

SRC_NAMES = megaphone.cpp

OBJS = $(SRC_NAMES:.cpp=.o)

all: $(NAME_TARGET)

$(NAME_TARGET): $(OBJS)
	$(PREFIX)$(COMPILER) $(OBJS) -o $(NAME_CURRENT) $(LINK_FLAGS)

%.o: %.cpp
	$(PREFIX)$(COMPILER) $(COMPILE_FLAGS) $< -o $@ $(INCLUDES) $(PREPROC_DEFINES)

clean:
	$(PREFIX)rm -f $(OBJS)

fclean: clean
	$(PREFIX)rm -f $(NAME_TARGET) $(NAME_TEST)

test:
	$(PREFIX)rm -f out.txt err.txt
	$(PREFIX)make all clean
	$(PREFIX)make PREPROC_DEFINES="$(PREPROC_DEFINES) -DTEST" NAME_CURRENT=$(NAME_TEST) all
	$(PREFIX)./$(NAME_TEST)
	$(PREFIX)rm -f out.txt err.txt

re: fclean all

retest: fclean test

PHONY: all pre clean fclean re test