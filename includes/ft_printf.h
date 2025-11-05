/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:32:09 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 17:29:22 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_format_raw
{
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	int		width;
	int		precision;
	int		precision_specified;
	char	specifier;
}	t_format_raw;

typedef enum e_align
{
	ALIGN_LEFT,
	ALIGN_RIGHT
}	t_align;

typedef enum e_padding
{
	PAD_NONE,
	PAD_ZERO,
	PAD_SPACE
}	t_padding;

typedef struct s_format
{
	t_align		align;
	t_padding	padding;
	size_t		width;
	size_t		precision;
	size_t		precision_specified;
	size_t		show_prefix;
	size_t		show_sign;
	size_t		flag_space;
	char		specifier;
}	t_format;

//parser
t_format	normalized_format(t_format_raw raw);
const char	*parse_flags(const char *fmt, t_format_raw *fmt_info);
const char	*parse_precision(const char *fmt, t_format_raw *fmt_info, \
	va_list args);
const char	*parse_width(const char *fmt, t_format_raw *fmt_info, va_list args);

// print
int			print_char_with_format(char c, t_format fmt);
int			print_string_with_format(const char *str, t_format fmt);
int			print_integer_with_format(int num, t_format fmt);
int			print_unsigned_with_format(unsigned int num, t_format fmt);
int			print_hex_with_format(unsigned int num, t_format fmt);
int			print_pointer_with_format(void *ptr, t_format fmt);
int			print_percent_with_format(t_format fmt);

//format_utils
char		*apply_precision(const char *num_str, t_format fmt);
char		*apply_precision_string(const char *str, t_format fmt);
char		*apply_sign(const char *num_str, long n, t_format fmt);
char		*apply_hash(const char *num_str, t_format fmt);
char		*apply_padding(const char *str, t_format fmt);

//format
char		*format_number(const char *num_str, long n, t_format fmt);
char		*format_char(char c, t_format fmt);
char		*format_string(const char *str, t_format fmt);

//utils
char		*ft_utoa(unsigned int n);
char		*ft_itoa_base(unsigned long long n, int base, int uppercase);
char		*ft_itoa_2(int n);

int			ft_printf(const char *fmt, ...);

#endif