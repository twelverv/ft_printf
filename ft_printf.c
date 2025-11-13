/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:14:14 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/12 11:42:34 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_format(t_format fmt_info, va_list args)
{
	if (fmt_info.specifier == 'c')
		return (print_char_with_format(va_arg(args, int), fmt_info));
	else if (fmt_info.specifier == 's')
		return (print_string_with_format(va_arg(args, char *), fmt_info));
	else if (fmt_info.specifier == 'd' || fmt_info.specifier == 'i')
		return (print_integer_with_format(va_arg(args, int), fmt_info));
	else if (fmt_info.specifier == 'u')
		return (print_unsigned_with_format(va_arg(args, unsigned int), \
			fmt_info));
	else if (fmt_info.specifier == 'x')
		return (print_hex_with_format(va_arg(args, unsigned int), fmt_info));
	else if (fmt_info.specifier == 'X')
		return (print_hex_with_format(va_arg(args, unsigned int), fmt_info));
	else if (fmt_info.specifier == 'p')
		return (print_pointer_with_format(va_arg(args, void *), fmt_info));
	else if (fmt_info.specifier == '%')
		return (print_percent_with_format(fmt_info));
	return (0);
}

static int	handle_format(const char **fmt, va_list args)
{
	t_format_raw	fmt_raw;
	t_format		fmt_info;
	int				printed;

	ft_bzero(&fmt_raw, sizeof(fmt_raw));
	*fmt = parse_flags(*fmt, &fmt_raw);
	*fmt = parse_width(*fmt, &fmt_raw, args);
	*fmt = parse_precision(*fmt, &fmt_raw, args);
	fmt_raw.specifier = **fmt;
	if (!fmt_raw.specifier)
		return (0);
	fmt_info = normalized_format(fmt_raw);
	printed = apply_format(fmt_info, args);
	if (printed < 0)
		return (-1);
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		printed;
	int		count;

	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!*fmt)
				break ;
			printed = handle_format(&fmt, args);
			if (printed < 0)
				return (-1);
			count += printed;
		}
		else
			count += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (count);
}
