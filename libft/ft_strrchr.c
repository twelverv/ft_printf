/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:13:55 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/20 18:04:25 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	letter;
	int		count;

	letter = (char)c;
	count = 0;
	while (*s)
	{
		s ++;
		count ++;
	}
	if (letter == '\0')
		return ((char *)s);
	while (count > 0)
	{
		s --;
		count --;
		if (*s == letter)
			return ((char *)s);
	}
	return (NULL);
}
