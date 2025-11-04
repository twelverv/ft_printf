/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_with_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:29:45 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 12:31:19 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent_with_format(t_format fmt)
{
	char	*str;
	int		len;
	int		written;

	str = format_char('%', fmt);
	if (!str)
		return (-1);

	len = ft_strlen(str);
	written = write(1, str, len);
	free(str);
	return (written);
}
