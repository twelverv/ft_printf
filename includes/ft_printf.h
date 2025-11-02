/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:32:09 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/02 22:14:10 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

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

//utils
char		*apply_precision(const char *num_str, t_format fmt);
char		*apply_sign(const char *num_str, long n, t_format fmt);

#endif