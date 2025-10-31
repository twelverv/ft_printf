/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:42:02 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/20 18:04:37 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*arr;
	size_t	total_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	total_len = ft_strlen(s);
	arr = malloc(total_len + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i ++;
	}
	arr[i] = '\0';
	return (arr);
}
