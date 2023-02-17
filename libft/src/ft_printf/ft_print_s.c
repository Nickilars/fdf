/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:58:34 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/17 10:06:38 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_s(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_print_s("(null)");
		return (i);
	}
	while (str[i])
		ft_print_c(str[i++]);
	return (i);
}

/*int	main(int ac, char **av)
{
	(void) ac;
	ft_putstr(av[1]);
	return (0);
}*/
