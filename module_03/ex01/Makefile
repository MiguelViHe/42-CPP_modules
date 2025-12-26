# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 10:02:29 by mvidal-h          #+#    #+#              #
#    Updated: 2025/12/26 10:07:57 by mvidal-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
EXERCISE	=	ex01

CC			=	c++
CPPFLAGS		=	-Wall -Werror -Wextra -std=c++98 #-fsanitize=address

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#source files
SRC_FILES	=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@echo -e "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo -e "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CPPFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo -e "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo -e "$(BLUE)Deleting all objects from /$(EXERCISE)...$(RESET)"; else \
	echo -e "No objects to remove from /$(EXERCISE)."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo -e "$(BLUE)Deleting $(NAME) from $(EXERCISE)...$(RESET)"; else \
	echo -e "No Executable to remove from $(EXERCISE)."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re