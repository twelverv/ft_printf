/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_with_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:18:30 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 10:39:59 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

int	print_char_with_format(char c, t_format fmt)
{
	char	*str;
	int		count;

	count = 0;
	str = format_char(c, fmt);
	if (!str)
		return (-1);
	count += write(1, str, ft_strlen(str));
	free(str);
	return (count);
}
