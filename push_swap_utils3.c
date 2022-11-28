/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:35:49 by ajafy             #+#    #+#             */
/*   Updated: 2022/06/30 17:30:26 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_index(t_list **stack_a, int *tab, int size)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		while (i < size)
		{
			if (tab[i] == (*stack_a)->content)
			{
				(*stack_a)->index = i;
				break ;
			}
			i++;
		}
		i = 0;
		(*stack_a) = (*stack_a)->next;
	}
}

int	get_index(t_list **stack_a, int indeex)
{
	int		index;
	t_list	*stack;

	index = 1;
	stack = (*stack_a);
	while ((stack))
	{
		if ((stack)->index == indeex)
			break ;
		index++;
		stack = (stack)->next;
	}
	return (index);
}

int	get_min(t_list **stack_a)
{
	t_list	*index;
	t_list	*stack;
	int		min;

	stack = (*stack_a);
	index = ft_lstlast(stack);
	min = index->index;
	while ((stack))
	{
		if ((stack)->index < min)
			min = (stack)->index;
		stack = (stack)->next;
	}
	return (min);
}

int	get_max(t_list **stack_a)
{
	t_list	*stack;
	t_list	*index;
	int		max;

	stack = (*stack_a);
	index = ft_lstlast(stack);
	max = index->index;
	while ((stack))
	{
		if ((stack)->index > max)
			max = (stack)->index;
		stack = (stack)->next;
	}
	return (max);
}

void	ft_find_min(t_list **stack_a)
{
	int		min;
	int		index;
	int		size;
	t_list	*head;

	head = (*stack_a);
	min = get_min(stack_a);
	index = get_index(stack_a, min);
	size = ft_lstsize(head);
	if (index <= size / 2)
	{
		while (index > 1)
		{
			ra(stack_a, 0);
			index--;
		}
	}
	else
	{
		while (index <= size)
		{	
			rra(stack_a, 0);
			index++;
		}
	}
}
