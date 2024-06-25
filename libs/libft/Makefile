# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 23:59:26 by muabdi            #+#    #+#              #
#    Updated: 2024/06/20 22:58:06 by muabdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = ./includes
LIBS = ./modules

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDEFLAGS = -I$(INCLUDES)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

SRC_DIR = ./src
OBJ_DIR = ./bin

CONVERSION_DIR = $(SRC_DIR)/conversion
MEMORY_DIR = $(SRC_DIR)/memory
STRING_DIR = $(SRC_DIR)/string
CHECK_DIR = $(SRC_DIR)/check
LIST_DIR = $(SRC_DIR)/list
IO_DIR = $(SRC_DIR)/io

CONVERSION_SRCS = $(CONVERSION_DIR)/ft_atoi.c \
$(CONVERSION_DIR)/ft_itoa.c \
$(CONVERSION_DIR)/ft_tobase.c \
$(CONVERSION_DIR)/ft_tolower.c \
$(CONVERSION_DIR)/ft_toupper.c \
$(CONVERSION_DIR)/ft_strupr.c

MEMORY_SRCS = $(MEMORY_DIR)/ft_bzero.c \
$(MEMORY_DIR)/ft_calloc.c \
$(MEMORY_DIR)/ft_memchr.c \
$(MEMORY_DIR)/ft_memcmp.c \
$(MEMORY_DIR)/ft_memcpy.c \
$(MEMORY_DIR)/ft_memmove.c \
$(MEMORY_DIR)/ft_memset.c \
$(MEMORY_DIR)/ft_realloc.c

STRING_SRCS = $(STRING_DIR)/ft_strchr.c \
$(STRING_DIR)/ft_strdup.c \
$(STRING_DIR)/ft_striteri.c \
$(STRING_DIR)/ft_strjoin.c \
$(STRING_DIR)/ft_strlcat.c \
$(STRING_DIR)/ft_strlcpy.c \
$(STRING_DIR)/ft_strlen.c \
$(STRING_DIR)/ft_strmapi.c \
$(STRING_DIR)/ft_strncmp.c \
$(STRING_DIR)/ft_strnstr.c \
$(STRING_DIR)/ft_strrchr.c \
$(STRING_DIR)/ft_strtrim.c \
$(STRING_DIR)/ft_substr.c \
$(STRING_DIR)/ft_split.c \
$(STRING_DIR)/ft_strtok.c

CHECK_SRCS = $(CHECK_DIR)/ft_isalnum.c \
$(CHECK_DIR)/ft_isalpha.c \
$(CHECK_DIR)/ft_isascii.c \
$(CHECK_DIR)/ft_isdigit.c \
$(CHECK_DIR)/ft_isprint.c \

LIST_SRCS = $(LIST_DIR)/ft_lstadd_back.c \
$(LIST_DIR)/ft_lstadd_front.c \
$(LIST_DIR)/ft_lstclear.c \
$(LIST_DIR)/ft_lstdelone.c \
$(LIST_DIR)/ft_lstiter.c \
$(LIST_DIR)/ft_lstlast.c \
$(LIST_DIR)/ft_lstmap.c \
$(LIST_DIR)/ft_lstnew.c \
$(LIST_DIR)/ft_lstsize.c

IO_SRCS = $(IO_DIR)/ft_putchar_fd.c \
$(IO_DIR)/ft_putendl_fd.c \
$(IO_DIR)/ft_putnbr_fd.c \
$(IO_DIR)/ft_putstr_fd.c \
$(IO_DIR)/ft_putunbr_fd.c\
$(IO_DIR)/get_next_line.c \
$(IO_DIR)/ft_printf.c

SRCS = $(CONVERSION_SRCS) $(MEMORY_SRCS) $(STRING_SRCS) $(CHECK_SRCS) $(IO_SRCS) $(LIST_SRCS)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME) $(OBJ_DIR)

$(OBJ_DIR):
	@echo "${YELLOW}Creating object directory $(OBJ_DIR)...${NC}"
	@mkdir -p $(OBJ_DIR)
	@echo "${GREEN}Object directory $(OBJ_DIR) created.${NC}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDEFLAGS) -c $< -o $@

${NAME}: $(OBJS) 
	@echo "${YELLOW}Creating archive '$(NAME)'...${NC}"
	@ar rcs $(NAME) $(OBJS)
	@echo "${GREEN}Archive '$(NAME)' created.${NC}" 

clean:
	@echo "${YELLOW}Starting target 'clean'...${NC}"
	@echo "${YELLOW}Cleaning object files...${NC}"
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}Object files cleaned.${NC}"
	@echo "${GREEN}Target 'clean' completed.${NC}"

fclean: clean
	@echo "${YELLOW}Cleaning archive $(NAME)...${NC}"
	@rm -f $(NAME)
	@echo "${GREEN}Archive $(NAME) cleaned.${NC}"
	@echo "${GREEN}Target 'fclean' completed.${NC}"

re: fclean all
	@echo "${GREEN}Target 're' completed.${NC}"

.PHONY: all clean fclean re
