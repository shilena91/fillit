# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 15:01:10 by hopham            #+#    #+#              #
#    Updated: 2019/12/31 15:53:31 by hopham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fillit

MAIN_NAME		=	main.c
LIB_FOLDER		=	./libft/
LIB_FILE		=	$(LIB_FOLDER)libft.a
LIB_FILES		=	$(LIB_FOLDER)*.c
LIB_OBJ			=	$(LIB_FOLDER)*.o
LIB				=	ft

C_FLAGS			=	-Wall -Werror -Wextra
SRCS			=	./srcs/
C_FUNCTIONS		=	validate_one_map tetrominos create_new_map get_next_line solve validate_whole_map free_memory

INCLUDES		= 	-I $(SRCS) -I $(LIB_FOLDER)
C_FILES		=	$(addprefix $(SRCS), $(addsuffix .c, $(C_FUNCTIONS)))
C_OBJ		=	                     $(addsuffix .o, $(C_FUNCTIONS))

all: $(NAME)

$(NAME):
	@make -C $(LIB_FOLDER) re
	gcc $(C_FLAGS) $(INCLUDES) -c $(C_FILES)
	gcc $(C_FLAGS) -o $(NAME) $(INCLUDES) -L $(LIB_FOLDER) -l $(LIB) $(SRCS)$(MAIN_NAME) $(C_OBJ)

clean:
	\rm -f $(C_OBJ) $(LIB_FOLDER)*.o

fclean: clean
	\rm -f $(NAME) $(LIB_FILE)

re: fclean all

.PHONY: re fclean clean all

