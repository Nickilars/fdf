/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:47:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/10 15:22:55 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// #include <stdio.h>

int	ft_btoi(int binaire) //binaire to decimal conversion
{
	int		d = 0;
	char	*b = ft_itoa(binaire);
	int		power = ft_strlen(b) - 1;
	int		i = 0;

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