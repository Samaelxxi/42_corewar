/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:12:00 by vpaladii          #+#    #+#             */
/*   Updated: 2017/10/28 19:12:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int base, int exp)
{
	int i;
	int res;

	if (exp == 0)
		return (1);
	i = 1;
	res = base;
	while (i < exp)
	{
		res *= base;
		i++;
	}
	return (res);
}
