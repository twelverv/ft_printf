/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_with_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:05:31 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 10:31:56 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer_with_format(void *ptr, t_format fmt)
{
	unsigned long long	addr;
	char				*num_str;
	char				*tmp;
	char				*res;
	int					count;

	addr = (unsigned long long)ptr;
	count = 0;
	num_str = ft_itoa_base(addr, 16, 0);
	if (!num_str)
		return (-1);
	tmp = ft_strjoin("0x", num_str);
	if (!tmp)
		return (-1);
	res = format_number(tmp, addr, fmt);
	free(num_str);
	if (!res)
		return (-1);
	count += write(1, res, ft_strlen(num_str));
	free(res);
	return (count);
}
