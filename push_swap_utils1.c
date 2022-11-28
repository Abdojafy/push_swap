/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:20:41 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 22:56:55 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rra(t_list **stack_a, int x)
{
	int		temp;
	t_list	*p;

	if (ft_lstsize((*stack_a)) > 1)
	{
		p = (*stack_a);
		temp = ft_lstlast(p)->content;
		ft_lstadd_front(stack_a, ft_lstnew(temp, ft_lstlast(p)->index));
		ft_free_lstlast(&p);
		if (x == 0)
			ft_printf("rra\n");
	}
}

void	rrb(t_list **stack_b, int x)
{
	int		temp;
	t_list	*p;

	if (ft_lstsize((*stack_b)) > 1)
	{
		p = (*stack_b);
		temp = ft_lstlast(p)->content;
		ft_lstadd_front(stack_b, ft_lstnew(temp, ft_lstlast(p)->index));
		ft_free_lstlast(&p);
		if (x == 0)
			ft_printf("rrb\n");
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, int x)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (x == 0)
		ft_printf("rrr\n");
}

void	pa(t_list **stack_a, t_list **stack_b, int x)
{
	if (ft_lstsize(*stack_b) >= 1)
	{
		push(stack_b, stack_a);
		if (x == 0)
			ft_printf("pa\n");
	}
}

void	pb(t_list **stack_a, t_list **stack_b, int x)
{
	if (ft_lstsize(*stack_a) >= 1)
	{
		push(stack_a, stack_b);
		if (x == 0)
			ft_printf("pb\n");
	}
}
