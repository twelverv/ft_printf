/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:25:47 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/20 19:18:16 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	ft_isspace(const char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (true);
	return (false);
}

static bool	check_sign(const char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	while (ft_isspace(*nptr))
		nptr ++;
	sign = 1;
	if (check_sign(*nptr))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr ++;
	}
	res = 0;
	while (ft_isdigit((int)*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr ++;
	}
	return (sign * res);
}
