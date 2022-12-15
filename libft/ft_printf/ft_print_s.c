/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:58:34 by nrossel           #+#    #+#             */
/*   Updated: 2022/11/16 17:14:13 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(const char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str == NULL)
	{
		ret += ft_print_s("(null)");
		return (ret);
	}
	while (str[i])
		ret += ft_print_c(str[i++]);
	return (ret);
}

/*int	main(int ac, char **av)
{
	(void) ac;
	ft_putstr(av[1]);
	return (0);
}*/
