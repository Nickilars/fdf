/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 08:25:33 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/10 11:01:46 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

int	ft_btoi(int nbr) //nbr max = 1023
{
	long long	d = 0;
	int			len = ft_nbrlen_b(nbr);
	char		*b = NULL;

	b = (char *)malloc((len + 1) * sizeof(char));
	if (!b)
		return (0);
	len--;
	while(len >= 0)
	{
		b[len] = (nbr % 2) + '0';
		nbr /= 2;
		len--;
	}
	d = ft_atoi(b);
	return (d);
}
// 
// int main(int ac, char **av)
// {
	// (void) ac;
	// int b = atoi(av[1]);
	// int decimal = ft_btoi(b);
	// printf("%d", decimal);
// }