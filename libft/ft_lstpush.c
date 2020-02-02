/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmacias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:16:09 by tmacias           #+#    #+#             */
/*   Updated: 2020/01/16 21:59:31 by tmacias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_memalloc(sizeof(*new));
	if (!new)
		return ;
	new->next = *lst;
	new->content = content;
	new->content_size = 0;
	*lst = new;
}
