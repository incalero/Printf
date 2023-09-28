NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
OBJ_DIR = obj

SRC_FILES = ft_printf.c \
            ft_printf_utils.c \


HEADER = printf.h
LIBC = ar rcs

CLR_RMV     := \033[0m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m

define  ART
$/\n
$(YELLOW):::::::::  :::::::::  ::::::::::: ::::    ::: :::::::::::     ::::::::::     
$(YELLOW):+:    :+: :+:    :+:     :+:     :+:+:   :+:     :+:         :+:             
$(GREEN)+:+    +:+ +:+    +:+     +:+     :+:+:+  +:+     +:+         +:+       
$(GREEN)+#++:++#+  +#++:++#:      +#+     +#+ +:+ +#+     +#+         :#::+::#     
$(CYAN)+#+        +#+    +#+     +#+     +#+  +#+#+#     +#+         +#+     
$(BLUE)#+#        #+#    #+#     #+#     #+#   #+#+#     #+#         #+#             
$(BLUE)###        ###    ### ########### ###    ####     ###         ###              
$(CLR_RMV)
$/\n
endef
export  ART

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	@echo "$$ART"
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re