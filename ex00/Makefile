NAME		= fixed
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR		= obj

SRCS		= src/main.cpp \
			  src/Fixed.cpp

OBJS		= $(SRCS:src/%.cpp=$(OBJDIR)/%.o)

INCLUDES	= -Iinclude

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 