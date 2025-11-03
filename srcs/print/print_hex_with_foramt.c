/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_with_foramt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:59:38 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 15:03:49 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_with_format(unsigned int num, t_format fmt)
{
	char	*num_str;
	char	*res;
	size_t	len;

	if (fmt.specifier == 'x')
		num_str = ft_itoa_base(num, 16, 0);
	else
		num_str = ft_itoa_base(num, 16, 1);
	if (!num_str)
		return (-1);
	res = format_number(num_str, num, fmt);
	if (!res)
		return (-1);
	free(num_str);
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}
