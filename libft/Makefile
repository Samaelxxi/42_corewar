# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpaladii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 10:55:46 by vpaladii          #+#    #+#              #
#    Updated: 2018/01/06 04:22:09 by vpaladii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
CC = gcc


INCLUDES = -I includes/

HEADERS = includes/libft.h


NUM_FILES = ft_atoi.c ft_itoa.c ft_pow.c num_len_in_chars.c min_in_arr.c
NUM_FILES := $(addprefix numeric/,$(NUM_FILES))

OUT_FILES = ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putstrarr.c \
ft_putintarr.c
OUT_FILES := $(addprefix output/,$(OUT_FILES))

PRF_FILES = ft_printf.c spec.c parsing.c print_wchar.c define_type.c \
            print_signed_decimal.c print_unsigned.c process_width.c other.c \
            process_precision.c itoas.c print_chars.c colors.c print_ptr.c parsing2.c \
            print_other.c
PRF_FILES := $(addprefix output/ft_printf/,$(PRF_FILES))

OTH_FILES = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
            ft_isprint.c ft_isspace.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
            ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_tolower.c ft_toupper.c \
            ft_wcrtomb.c get_next_line.c ft_is_hex.c wait_for_anykey.c
OTH_FILES := $(addprefix other/,$(OTH_FILES))

PTH_FILES = path_concat.c path_base.c
PTH_FILES := $(addprefix other/,$(PTH_FILES))

STR_FILES = char_idx.c char_in_str.c count_words.c free_str_arr.c ft_strcat.c \
            ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
            ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
            ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
            ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strreplace.c \
            ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c reverse_str.c \
            sort_str_arr.c starts_with.c str_arr_len.c str_in_arr.c str_is_numeric.c \
            str_to_upper.c remove_whitespaces.c str_is_hex.c read_file_to_str.c count_chars.c

STR_FILES := $(addprefix other/,$(STR_FILES))

SCT_FILES = circular_double_linked_list.c queue.c ft_lst1.c ft_lst2.c ft_lst3.c \
lst_deleters.c
SCT_FILES :=  $(addprefix other/,$(SCT_FILES))


FILES = $(NUM_FILES) $(OUT_FILES) $(PRF_FILES) $(OTH_FILES) $(PTH_FILES) $(STR_FILES) $(SCT_FILES)
_OBJ = $(addprefix obj/,$(notdir $(FILES:.c=.o)))



all: $(NAME)

$(NAME): objdir $(_OBJ)
	@ar rc $(NAME) $(_OBJ)
	@echo "\033[32m[Library is done]\033[00m"

objdir:
	@mkdir -p obj

obj/%.o: numeric/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

obj/%.o: output/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

obj/%.o: output/ft_printf/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) -I output/ft_printf/includes

obj/%.o: other_funcs/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

obj/%.o: path_funcs/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

obj/%.o: string/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

obj/%.o: structs/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -f $(_OBJ)
	rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re
