/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:59:32 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/21 17:18:53 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	scan_mem(unsigned char *dst, const unsigned char *source, size_t n)
{
	size_t	i;

	if (dst < source)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = source[i];
			i ++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = source[i - 1];
			i --;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*source;

	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	scan_mem(dst, source, n);
	return (dest);
}
