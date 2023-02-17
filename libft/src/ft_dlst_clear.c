/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:10:30 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/17 09:11:24 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_dlst_clear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*ptr2;

	if (!*dlst)
		return ;
	ptr2 = *dlst;
	while ((*dlst)->head != NULL)
	{
		ptr2 = (*dlst)->head->next;
		ft_lstdelone(NULL, (*dlst)->head, del);
		(*dlst)->head = ptr2;
	}
	*dlst = NULL;
}
