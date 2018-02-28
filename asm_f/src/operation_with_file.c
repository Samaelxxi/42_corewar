/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_with_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgnylyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:46:00 by vgnylyan          #+#    #+#             */
/*   Updated: 2018/02/15 13:46:00 by vgnylyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		open_file(int argc, char **argv)
{
	int fd;

	if (argc == 1)
	{
		ft_printf("Usage: ./asm <sourcefile.s>\n");
		exit(0);
	}
	else
	{
		if (!check_file_name(argv[argc - 1]))
			str_error("File must be with extension \".s\"\n");
		fd = open(argv[argc - 1], O_RDONLY);
		if (fd < 0)
			ft_perror(1);
	}
	if (read(fd, NULL, 0) == -1)
		ft_perror(1);
	return (fd);
}

int		create_newfile(char *file_name)
{
	int		fd_file;

	fd_file = -1;
	if (file_name)
	{
		ft_change_extension_to_cor(&file_name);
		if ((fd_file = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
		{
			ft_printf("Problem with creating file %s\n", file_name);
			exit(1);
		}
		else
			ft_printf("Writing output program to %s\n", file_name);
	}
	free(file_name);
	return (fd_file);
}

int		check_file_name(char*file_name)
{
	unsigned	orig_size_filename;

	orig_size_filename = ft_strlen(file_name);
	if (orig_size_filename < 3)
		str_error("File name must be longer than 2 characters");
	if (file_name[orig_size_filename - 2] == '.')
		if (file_name[orig_size_filename - 1] == 's')
			return (1);
	return (0);
}

void	ft_change_extension_to_cor(char **file_name)
{
	(*file_name)[ft_strlen(*file_name) - 1] = '\0';
	*file_name = ft_strjoin(*file_name, "cor");
}