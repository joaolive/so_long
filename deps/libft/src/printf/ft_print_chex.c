/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:18:19 by joaolive          #+#    #+#             */
/*   Updated: 2025/07/31 11:46:49 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chex(va_list args)
{
	unsigned int	num;

	num = (unsigned int)va_arg(args, unsigned int);
	return (ft_puthex(num, sizeof(num), 'X'));
}
