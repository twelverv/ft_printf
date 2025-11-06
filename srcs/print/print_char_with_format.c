/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_with_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:18:30 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/05 11:13:05 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_with_format(char c, t_format fmt)
{
	int	count;
	int	pad_len;

	count = 0;
	pad_len = fmt.width - 1;
	if (pad_len < 0)
		pad_len = 0;
	count += format_char(fmt, c, pad_len);
	return (count);
}
