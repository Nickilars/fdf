/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2da.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:50:21 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/02 11:19:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_free_2da(char **tab, int len)
{
	int i = 0;

	if (!tab)
		return (0);
	while (i < len)
		free(tab[i++]);
	return (1);
}