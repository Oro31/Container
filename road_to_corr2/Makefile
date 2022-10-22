CPPFLAGS = -Wall -Wextra -Werror -MMD#-std=c++98

CC = c++

NAME = container

SRC = main.cpp

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

annihilation:
	make run -C ./anniliation

.PHONY: annihilation clean fclean all re .cpp.o
