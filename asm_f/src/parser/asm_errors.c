/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:02:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 14:02:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		print_pars_error(t_parsing_error *err, t_line_of_tokens *line_of_tokens)
{
	if (err->error_code == LEXICAL_ERROR)
		ft_printf("error: Lexical error at token ");
	if (err->error_code == IND_LABEL_ERROR)
		ft_printf("error: label \"%s\" does not exist in the file at ",
				  err->error_token->token_string + 1);
	if (err->error_code == INSTR_ERROR)
		ft_printf("error: invalid instruction \"%s\" at ",
				  err->error_token->token_string);
	if (err->error_code == DIR_LABEL_ERROR)
		ft_printf("error: label \"%s\" does not exist in the file at ",
				  err->error_token->token_string + 2);
	ft_printf("[%03d : %03u]\n\t%s\n\t%*c\n", line_of_tokens->line_number,
			  err->error_token->start_lexem_position,
			  line_of_tokens->origin_line, err->error_token->start_lexem_position, '^');
	free(err);
	return (0);
}

void	ft_perror(int exit_value)
{
	perror("error");
	exit (exit_value);
}

void	lex_error(int nbr_line, char *text)
{
	ft_printf("Lexical error at [line %i] (%s)\n", nbr_line, text);
	exit(1);
}

void	str_error( char *text)
{
	ft_printf("error: %s\n", text);
	exit(1);
}

int		syntax_error(int nbr_line, int token_position, char *line, int err)
{
	if (err == INV_FISRT_TOKEN)
		ft_printf("error: First word in line have to be instruction or label [%03d : %03u]\n       %s\n%*c\n",
		nbr_line, token_position, line, token_position + 7, '^');
	if (err == NO_ARGS)
		ft_printf("error: Line without arguments at [%03d]\n     =>%s\n", nbr_line, line);
	if (err == INV_TYPE_ERR)
		ft_printf("error: Invalid type of argument at [%03d : %03u]\n       %s\n%*c\n",
				  nbr_line, token_position, line, token_position + 7, '^');
	if (err == EXTRA_ARGS_ERR)
		ft_printf("error: Extra argument at line [%03d]\n   >   %s\n",
				  nbr_line, line);
	if (err == NOT_ENOUGH_ARGS)
		ft_printf("error: In this position must be next argument [%03d : %03u]\n       %s\n%*c\n",
				  nbr_line, token_position, line, token_position + 7, '^');
	if (err == NOT_SEPARATOR)
		ft_printf("error: Arguments must be separated by a separator \",\" at line [%03d]\n    >  %s\n",
				  nbr_line, line);
	return (0);
}
