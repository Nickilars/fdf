/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:42:58 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/17 10:06:42 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_p(unsigned long nb)
{
	int	ret;

	ret = 0;
	ret += ft_print_s("0x");
	if (nb == 0)
		ret += ft_print_c('0');
	else
		ret += ft_print_hex(nb, 'x');
	return (ret);
}
