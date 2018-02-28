/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <vdubinki@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:06:00 by vdubinki          #+#    #+#             */
/*   Updated: 2018/02/26 14:06:00 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int 	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: %s <champion.cor>\n", argv[0]);
		return (0);
	}
	if (!is_correct_file(argv[1]))
	{
		ft_printf("Can't read source file %s\n", argv[1]);
		return (0);
	}
	if (!check_filename(argv[1]))
	{
		ft_printf("File must be with extension \".cor\"\n");
		return (0);
	}
	return (1);
}

int 	get_fd(char *filename)
{
	int 	fd;

	ft_change_extension_to_s(&filename);
	if ((fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
		ft_printf("Problem with creating file %s\n", filename);
	else
		ft_printf("Writing output program to %s\n", filename);
	free(filename);
	return (fd);
}

void	ft_change_extension_to_s(char **file_name)
{
	(*file_name)[ft_strlen(*file_name) - 3] = '\0';
	*file_name = ft_strjoin(*file_name, "s");
}

int		check_filename(char *filename)
{
	if (filename[ft_strlen(filename) - 4] == '.')
		if (!ft_strcmp(&filename[ft_strlen(filename) - 3], "cor"))
			return (1);
	return (0);
}
