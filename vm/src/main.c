/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:22:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/14 16:22:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_input_data *data;
	t_vm *vm;

	data = read_input_data(argc, argv);
	if (!data)
		return (0);
	vm = init_vm(data);
	run_vm(vm);
	free_data(vm, data);

	return (0);
}
