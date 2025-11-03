/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalized_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:18:56 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 11:43:53 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	normalized_format(t_format_raw raw)
{
	t_format	fmt;

	ft_bzero(&fmt, sizeof(t_format));
	if (raw.flag_minus)
		fmt.align = ALIGN_LEFT;
	else
		fmt.align = ALIGN_RIGHT;
	if (raw.flag_zero && !raw.flag_minus && !raw.precision_specified)
		fmt.padding = PAD_ZERO;
	else
		fmt.padding = PAD_SPACE;
	fmt.show_sign = raw.flag_plus;
	fmt.show_prefix = raw.flag_hash;
	fmt.flag_space = raw.flag_space;
	fmt.width = raw.width;
	fmt.precision = raw.precision;
	fmt.precision_specified = raw.precision_specified;
	fmt.specifier = raw.specifier;
	return (fmt);
}
