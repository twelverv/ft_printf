/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:28:20 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/21 14:26:52 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	judge_len(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	char	*spare;
	size_t	s_len;
	size_t	total_len;

	if (!s)
		return (NULL);
	spare = (char *)s;
	total_len = ft_strlen(spare);
	if (start >= total_len)
		return (ft_strdup(""));
	s_len = ft_strlen(s + start);
	len = judge_len(len, s_len);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, spare + start, len + 1);
	return (arr);
}
