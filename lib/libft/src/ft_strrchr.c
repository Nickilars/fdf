/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:09:26 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/15 19:28:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*to_find;

	to_find = (char *)s + ft_strlen(s);
	while ((char)c != *to_find)
	{
		if (to_find == s)
			return (NULL);
		to_find--;
	}
	return (to_find);
}
