/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2da.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:50:21 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/16 10:37:56 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_free_2da(char **tab, char *error_msg)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	if (error_msg != NULL)
		ft_free_arrays(NULL, NULL, error_msg);
	return (1);
}
