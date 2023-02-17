/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:47:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/17 09:03:45 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// #include <stdio.h>

int	ft_btoi(int binaire)
{
	int		d;
	char	*b;
	int		power;
	int		i;

	d = 0;
	i = 0;
	b = ft_itoa(binaire);
	power = ft_strlen(b) - 1;
	while (power >= 0)
	{
		if (b[power] == '1')
		{
			d += ft_power(2, i);
		}
		power--;
		i++;
	}
	free(b);
	return (d);
}

// int main(int ac, char **av)
// {
	// (void) ac;
	// int b = atoi(av[1]);
	// int decimal = ft_btoi(b);
	// printf("%d", decimal);
// }