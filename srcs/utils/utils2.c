/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:24:46 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 17:30:56 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digit_unsigned(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_2(int n)
{
	unsigned int	num;
	size_t			size;
	char			*res;

	if (n < 0)
		num = -n;
	else
		num = n;
	size = count_digit_unsigned(num);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (size-- > 0)
	{
		res[size] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
