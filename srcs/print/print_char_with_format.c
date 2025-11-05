/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_with_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:18:30 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 19:26:06 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

int	print_char_with_format(char c, t_format fmt)
{
	int	count;
	int	i;
	int	pad_len;

	count = 0;
	pad_len = fmt.width - 1;
	if (pad_len < 0)
		pad_len = 0;
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
