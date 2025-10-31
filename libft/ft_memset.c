/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 04:33:38 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/20 17:56:13 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	character;
	unsigned char	*str;

	character = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = character;
		i ++;
	}
	return (str);
}
