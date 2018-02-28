# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 10:55:46 by vpaladii          #+#    #+#              #
#    Updated: 2017/10/28 19:57:39 by vpaladii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c spec.c parsing.c print_wchar.c define_type.c \
print_signed_decimal.c print_unsigned.c process_width.c other.c \
process_precision.c itoas.c print_chars.c colors.c print_ptr.c parsing2.c \
print_other.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJDIR = ../../obj/
INCLUDES = -I ../includes/ -I includes/
OBJFILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJDIR),$(OBJFILES))

all: $(OBJ)

$(addprefix $(OBJDIR), %.o): %.c
	@$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean

re: clean all

.PHONY: clean all fclean re