/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:27:57 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/24 12:29:42 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_format(t_format *fmt)
{
	fmt->flag_minus = 0;
	fmt->flag_zero = 0;
	fmt->flag_hash = 0;
	fmt->flag_space = 0;
	fmt->flag_plus = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->precision_specified = 0;
	fmt->specifier = '\0';
}
