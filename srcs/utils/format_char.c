/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:04:43 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/05 11:13:15 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_char(t_format fmt, char c, int pad_len)
{
	int	count;
	int	i;

	count = 0;
	if (fmt.align == ALIGN_RIGHT)
	{
		i = 0;
		while (i < pad_len)
		{
			count += write(1, " ", 1);
			i++;
		}
		count += write(1, &c, 1);
	}
	else
	{
		count += write(1, &c, 1);
		i = 0;
		while (i < pad_len)
		{
			count += write(1, " ", 1);
			i++;
		}
	}
	return (count);
}
