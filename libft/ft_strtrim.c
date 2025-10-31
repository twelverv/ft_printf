/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:36:25 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/20 18:04:20 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	judge_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		count;
	char		*arr;
	const char	*start;
	const char	*end;

	if (!s1)
		return (NULL);
	while (*s1 && judge_set((char )*s1, set) == 1)
		s1 ++;
	start = s1;
	count = 0;
	end = s1 + ft_strlen (s1);
	while (end > start && judge_set((char )*(end - 1), set) == 1)
		end --;
	count = end - start;
	arr = malloc(sizeof(char) * (count + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, (char *)start, count + 1);
	return (arr);
}
