/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:04:43 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/13 16:28:10 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	padding_space(int pad_len)
{
	int res;
	int i;

	i = 0;
	while (i < pad_len)
	{
		res = write(1, " ", 1);
		if (res < 0)
			return (-1);
		i++;
	}
	return (pad_len);
}

int	format_char(t_format fmt, char c, int pad_len)
{
	int	count;
	int	res;

	count = 0;
	if (fmt.align == ALIGN_LEFT)
	{
		res = write(1, &c, 1);
		if (res < 0)
			return (-1);
		count += res;
	}
	res = padding_space(pad_len);
	if (res < 0)
		return (-1);
	count += res;
	if (fmt.align == ALIGN_RIGHT)
	{
		res = write(1, &c, 1);
		if (res < 0)
			return (-1);
		count += res;
	}
	return (count);
}
