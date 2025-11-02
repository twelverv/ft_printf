/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:55:06 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/02 21:55:44 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_sign(const char *num_str, long n, t_format fmt)
{
	char	sign_char;
	char	*res;

	sign_char = 0;
	if (n < 0)
		sign_char = '-';
	else if (fmt.show_sign)
		sign_char = '+';
	else if (fmt.flag_space)
		sign_char = ' ';
	if (sign_char)
	{
		res = malloc(ft_strlen(num_str) + 2);
		if (!res)
			return (NULL);
		res[0] = sign_char;
		ft_strlcpy((res + 1), num_str, (ft_strlen(num_str) + 1));
	}
	else
		res = ft_strdup(num_str);
	return (res);
}
