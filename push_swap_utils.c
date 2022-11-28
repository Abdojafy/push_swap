/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:34:21 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 22:54:03 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list **stack_a, int x)
{
	int	temp;
	int	j;

	j = 0;
	if (ft_lstsize((*stack_a)) > 1)
	{
		temp = (*stack_a)->content;
		j = (*stack_a)->index;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->index = (*stack_a)->next->index;
		(*stack_a)->next->content = temp;
		(*stack_a)->next->index = j;
		if (x == 0)
			ft_printf("sa\n");
	}
}

void	sb(t_list **stack_b, int x)
{
	int	temp;
	int	j;

	if (ft_lstsize((*stack_b)) > 1)
	{
		temp = (*stack_b)->content;
		j = (*stack_b)->index;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->index = (*stack_b)->next->index;
		(*stack_b)->next->content = temp;
		(*stack_b)->next->index = j;
		if (x == 0)
			ft_printf("sb\n");
	}
}

void	ss(t_list **stack_a, t_list **stack_b, int x)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	if (x == 0)
		ft_printf("ss\n");
}

void	ra(t_list **stack_a, int x)
{
	int		temp;
	t_list	*nd;
	int		j;

	if (ft_lstsize((*stack_a)) > 1)
	{
		temp = (*stack_a)->content;
		j = (*stack_a)->index;
		nd = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		ft_lstadd_back(stack_a, ft_lstnew(temp, j));
		if (x == 0)
			ft_printf("ra\n");
		free(nd);
	}
}

void	rb(t_list **stack_b, int x)
{
	int		temp;
	t_list	*nd;
	int		j;

	if (ft_lstsize((*stack_b)) > 1)
	{
		temp = (*stack_b)->content;
		j = (*stack_b)->index;
		nd = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		ft_lstadd_back(stack_b, ft_lstnew(temp, j));
		if (x == 0)
			ft_printf("rb\n");
		free(nd);
	}
}
