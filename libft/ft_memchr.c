/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:38:54 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/21 14:26:16 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		letter;
	size_t				i;

	i = 0;
	str = (const unsigned char *)s;
	letter = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == letter)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
