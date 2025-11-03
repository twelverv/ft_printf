/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:15:05 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 14:09:46 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strldup(const char *src, size_t len)
{
	char	*copy;
	size_t	i;

	copy = (char *) malloc (sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		copy[i] = src[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*apply_precision_string(const char *str, t_format fmt)
{
	size_t	len;

	if (!str)
		return (ft_strdup("(null)"));
	len = ft_strlen(str);
	if (fmt.precision_specified && fmt.precision < len)
		len = fmt.precision;
	return (ft_strldup(str, len));
}
