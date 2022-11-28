/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:58:05 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 22:58:00 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	if (stack_a)
	{
		p = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, ft_lstnew(p->content, p->index));
		free(p);
	}
}

void	ft_sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(stack_a, 0);
	}
}

void	ft_sort_three(t_list **stack_a)
{
	int	p1;
	int	p2;
	int	p3;

	p1 = (*stack_a)->index;
	p2 = (*stack_a)->next->index;
	p3 = (*stack_a)->next->next->index;
	if ((p1 < p2) && (p1 < p3) && (p2 > p3))
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	if ((p1 < p2) && (p1 > p3) && (p2 > p3))
		rra(stack_a, 0);
	if ((p1 > p2) && (p1 < p3) && (p2 < p3))
		sa(stack_a, 0);
	if ((p1 > p2) && (p1 > p3) && (p2 > p3))
	{
		ra(stack_a, 0);
		sa(stack_a, 0);
	}
	if ((p1 > p2) && (p1 > p3) && (p2 < p3))
		ra(stack_a, 0);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	ft_find_min(stack_a);
	pb(stack_a, stack_b, 0);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b, 0);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	ft_find_min(stack_a);
	pb(stack_a, stack_b, 0);
	ft_sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, 0);
}
