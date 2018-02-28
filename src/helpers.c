/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladii <vpaladii@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:33:00 by vpaladii          #+#    #+#             */
/*   Updated: 2018/02/22 13:33:00 by vpaladii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint8_t		get_arg_encoding(uint8_t enc_byte, unsigned arg_idx)
{
	return ((enc_byte >> (6 - 2 * arg_idx)) & 0x03);
}

uint32_t	swap_uint32(uint32_t value)
{
	return (((value >> 24) & 0xFF) |
			((value >> 8) & 0xFF00) |
			((value << 8) & 0xFF0000) |
			((value << 24) & 0xFF000000));
}

uint16_t	swap_uint16(uint16_t value)
{
	return (((value >> 8) & 0xFF) |
			((value << 8) & 0xFF00));
}
