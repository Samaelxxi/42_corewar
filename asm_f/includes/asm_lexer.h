/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <omakovsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:09:00 by omakovsk          #+#    #+#             */
/*   Updated: 2018/02/21 10:09:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ASM_LEXER_H
# define ASM_LEXER_H

#include "asm.h"
/*
**	asm_save_comment_champion.c
*/

void		save_comment_or_name(char **object, char *line, int *nbr_line, int fd);
void		put_comment_or_name_on_struct(char **object, char *line, int *nbr_line, int fd);
void		join_comment_or_name_to_each_other(char **object, char *line, int *nbr_line, int fd);
void		join_comment_or_name_together(char **object, char *str2);
int			check_comment_or_name(char *line);

/*
**	split_file_into_tokens.c
*/

void		split_file_into_tokens(t_file_of_tokens *head, int fd);
void		check_name_or_comment(t_file_of_tokens *head, char *line, int *nbr_line, int fd);


char				*ft_strtrim_end(char *s);
char				*ft_strtrim_start(char *s);
void				ft_perror(int error_value);
void				lex_error(int nbr_line, char *text);
void				str_error(char *text);
char				*ft_strtrim_free(char *s);
char				*ft_strtrim_start_free(char *s);
int					check_errors_in_line(t_line_of_tokens *line_of_tokens, t_list *header);
int 				search_state_column(char symbol);
void				write_token_in_list(t_line_of_tokens *head_line_token,
										int token_num, unsigned int start_token, char *token_string);
t_parsing_error		*check_lex_one_token(t_token *token, t_list *head_lines);
t_parsing_error		*check_present_token_error(t_line_of_tokens *line_of_tokens);
void				tokenize_file(t_file_of_tokens *head, int nbr_line, int fd);
void				ignore_space_at_start(char *line, unsigned int *position);
void				view_and_break_line(t_file_of_tokens *head, char *line, int nbr_line);
void				create_line_lexem(t_file_of_tokens *head, int nbr_line, char *line);
void				extract_one_token(t_line_of_tokens *head_line_token,
						  				char *line, unsigned *pos);
int					take_one_token(t_line_of_tokens *head_line_token, int *state,
						 	 		char *line, unsigned *pos);

#endif
