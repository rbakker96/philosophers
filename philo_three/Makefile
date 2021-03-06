# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: roybakker <roybakker@student.codam.nl>       +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/14 15:10:01 by roybakker     #+#    #+#                  #
#    Updated: 2021/01/07 15:14:28 by roybakker     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	philo_three

SOURCES			= 	main.c \
					srcs/error.c \
					srcs/healt_check_thread.c \
					srcs/input_validation.c \
					srcs/philo_thread.c \
					srcs/print_functions.c \
					srcs/time_calc.c \
					srcs/utils.c

OBJECTS 		=	${SOURCES:%.c=%.o}

FLAGS 			=	-Wall -Wextra -Werror -g -fsanitize=address
INCLUDES 		=	-I headers/
COMPILE			=	gcc

GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

ifeq ($(DEBUG),1)
    FLAGS += -g -fsanitize=address
endif

UNAME_S			:=	$(shell uname -s)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(INCLUDES) $(FLAGS) -lpthread -o $(NAME) $(OBJECTS)
	@echo "Executable				./philo_three"
	@echo "$(GREEN)----------------------------------------------------"

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(INCLUDES) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)REMOVED O-FILES philo_three"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE ./philo_three"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
