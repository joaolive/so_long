/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:14:19 by joaolive          #+#    #+#             */
/*   Updated: 2025/08/31 15:13:52 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../include/libft.h"

typedef int	(*t_format_handler)(va_list arg);

typedef struct s_handler
{
	char				specifier;
	t_format_handler	handler_func;
}						t_handler;

int	ft_printf(const char *arr, ...);
int	ft_handler_format(char specifier, va_list args);
int	ft_print_char(va_list args);
int	ft_print_str(va_list args);
int	ft_print_num(va_list args);
int	ft_print_unum(va_list args);
int	ft_print_lhex(va_list args);
int	ft_print_chex(va_list args);
int	ft_print_ptr(va_list args);
int	ft_print_percent(va_list args);
int	ft_puthex(unsigned long long num, size_t size_in_bytes, char specifier);

#endif
