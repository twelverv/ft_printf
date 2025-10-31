/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:02:46 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/20 17:55:54 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*let1 = s1;
	const unsigned char	*let2 = s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (let1[i] != let2[i])
			return (let1[i] - let2[i]);
		i++;
	}
	return (0);
}
