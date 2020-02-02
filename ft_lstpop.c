/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmacias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:38:27 by tmacias           #+#    #+#             */
/*   Updated: 2020/02/01 15:49:22 by tmacias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **lst)
{
	t_list	*temp;
	void	*tempcontent;
	
	tempcontent = (*lst)->content;
	temp = *lst;
	*lst = (*lst)->next;
	free(temp);

	return (tempcontent);
}
