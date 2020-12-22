# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: roybakker <roybakker@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/14 15:10:01 by roybakker     #+#    #+#                  #
#    Updated: 2020/12/22 15:30:22 by roybakker     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	philo_one

SOURCES			= 	main.c input_validation.c parsing.c print_functions.c threads.c eating.c time_calc.c error.c

OBJECTS 		=	${SOURCES:%.c=%.o}

FLAGS 			=	-Wall -Wextra -Werror
COMPILE			=	gcc
LIB				=	ar rc

GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

UNAME_S			:=	$(shell uname -s)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS) $(INLCUDES) -lpthread -o $(NAME) $(OBJECTS)
	@echo "Executable				./philo_one"
	@echo "$(GREEN)----------------------------------------------------"

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)REMOVED O-FILES philo_one"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE ./philo_one"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
