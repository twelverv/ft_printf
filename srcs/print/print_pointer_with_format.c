/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_with_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:05:31 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/05 11:11:01 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nil_pointer(t_format fmt)
{
	char	*res;
	int		count;

	res = apply_padding("(nil)", fmt);
	if (!res)
		return (-1);
	count = write(1, res, ft_strlen(res));
	free(res);
	return (count);
}

int	print_pointer_with_format(void *ptr, t_format fmt)
{
	unsigned long long	addr;
	char				*num_str;
	char				*tmp;
	char				*res;
	int					count;

	if (ptr == NULL)
		return (nil_pointer(fmt));
	addr = (unsigned long long)ptr;
	count = 0;
	num_str = ft_itoa_base(addr, 16, 0);
	if (!num_str)
		return (-1);
	tmp = ft_strjoin("0x", num_str);
	free(num_str);
	if (!tmp)
		return (-1);
	res = format_number(tmp, addr, fmt);
	free(tmp);
	if (!res)
		return (-1);
	count += write(1, res, ft_strlen(res));
	free(res);
	return (count);
}
