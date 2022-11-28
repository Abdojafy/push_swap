/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 08:38:18 by ajafy             #+#    #+#             */
/*   Updated: 2022/06/23 11:27:50 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, int (f)(int), void (*del)(int))
{
	t_list	*new;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(f(lst->content), 1));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
