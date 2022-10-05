CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

CC = c++

NAME = iter

SRC = main.cpp	\

OBJ = $(SRC:.cpp=.o)

DEP = $(OBJ:%.o=%.d)

all: $(NAME)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

-include $(DEP)

clean:
	rm -f $(OBJ)
	rm -f $(DEP)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean all re .cpp.o
