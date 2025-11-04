/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_with_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:38:37 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 10:34:58 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string_with_format(const char *str, t_format fmt)
{
	char	*res;
	char	*tmp;
	ssize_t	reply;
	int		count;

	res = format_string(str, fmt);
	if (!res)
		return (-1);
	if (!res)
		return (0);
	tmp = res;
	while (*tmp)
	{
		reply = write(1, tmp, 1);
		if (reply == -1)
			return (-1);
		tmp ++;
		count += reply;
	}
	free(res);
	return (count);
}
