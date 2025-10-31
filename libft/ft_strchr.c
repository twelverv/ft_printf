/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:06 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/20 17:56:42 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char)c;
	while (*s)
	{
		if (*s == letter)
			return ((char *)s);
		s ++;
	}
	if (letter == '\0')
		return ((char *)s);
	return (NULL);
}
