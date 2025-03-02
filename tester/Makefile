# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dds <dda-silv@student.42lisboa.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 09:33:15 by dda-silv          #+#    #+#              #
#    Updated: 2021/04/02 10:50:41 by dda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program built
NAME			:=		test

# Name directory
PATH_SRC		:=		src
PATH_FILES		:=		files
PATH_BUILD		:=		build
PATH_LIBASM		:=		..

# List of sources
SRCS			:=		$(shell find $(PATH_SRC) -name *.c)
OBJS			:=		$(SRCS:%.c=$(PATH_BUILD)/%.o)
DEPS			:=		$(OBJS:.o=.d)
INC_DIRS		:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC				:=		gcc

# Flags - compilation
FLAG_WARNING	:=		-Wall -Wextra -Werror
FLAG_INC		:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE	:=		-MMD -MP
FLAG_DEBUG		:= 		-g
FLAGS_COMP		:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG)

# Flags - memory leak check
FLAG_MEM_LEAK	:= 		-fsanitize=address

# Flags - linking
FLAGS_LINKING	:=		-L$(PATH_LIBASM) -lasm

# Others commands
RM				:=		rm -rf

# Functions
all:					init $(NAME)
						@ mkdir -p $(PATH_FILES)
						@ ./$(NAME)
						@ $(RM) $(NAME)
						@ $(RM) $(PATH_FILES)

lldb:					init $(NAME)
						@ mkdir -p $(PATH_FILES)
						@ lldb ./$(NAME)
						@ $(RM) $(NAME)
						@ $(RM) $(PATH_FILES)

debug:					FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:					re

init:
						@ make -C $(PATH_LIBASM) bonus

$(NAME):				$(OBJS)
						@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS) $(FLAGS_LINKING)


$(PATH_BUILD)/%.o:		%.c
						@ mkdir -p $(dir $@)
						@ $(CC) $(FLAGS_COMP) -c $< -o $@

clean:
						@ $(RM) $(PATH_BUILD)

fclean:					clean
						@ $(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re start

-include $(DEPS)

# Source for some pieces of this Makefile: 
# https://makefiletutorial.com/#makefile-cookbook
