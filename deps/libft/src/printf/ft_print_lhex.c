/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:18:19 by joaolive          #+#    #+#             */
/*   Updated: 2025/07/31 11:47:27 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lhex(va_list args)
{
	unsigned int	num;

	num = (unsigned int)va_arg(args, unsigned int);
	return (ft_puthex(num, sizeof(num), 'x'));
}
