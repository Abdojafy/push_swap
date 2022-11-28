/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:54:17 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 23:02:03 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	remplire_stack_b2(t_list **stack_a, t_list **stack_b, int i, int j)
{
	t_list	*p;

	p = *stack_a;
	while (ft_lstsize(*stack_a) > 0)
	{
		if (p->index < i)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
			i++;
		}
		else if (p->index < (i + j))
		{
			pb(stack_a, stack_b, 0);
			i++;
		}
		else
			ra(stack_a, 0);
		p = *stack_a;
		if (ft_lstsize(*stack_b) > 1)
			if ((*stack_b)->index < (*stack_b)->next->index)
				sb(stack_b, 0);
	}
}

void	remplire_stack_b(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	t_list	*p;

	i = 1;
	j = 15;
	if (ft_lstsize(*stack_a) > 250)
		j = 25;
	p = *stack_a;
	remplire_stack_b2(stack_a, stack_b, i, j);
}

void	remplire_stack_a(t_list **stack_a, t_list **stack_b)
{
	int		position;
	int		middle;
	int		x;

	while (ft_lstsize(*stack_b) > 0)
	{
		if (*stack_b)
		{
			x = 0;
			position = get_index(stack_b, get_max(stack_b));
			middle = get_index(stack_b, get_middle(*stack_b));
			if (position <= middle)
			{
				while (x++ < position - 1)
					rb(stack_b, 0);
				pa(stack_a, stack_b, 0);
			}
			else if (position > middle)
			{
				while (x++ < ft_lstsize(*stack_b) - position + 1)
					rrb(stack_b, 0);
				pa(stack_a, stack_b, 0);
			}
		}
	}
}

void	sort_big_stack(t_list **stack_a, t_list **stack_b)
{
	remplire_stack_b(stack_a, stack_b);
	remplire_stack_a(stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack;

	stack_a = NULL;
	stack_b = NULL;
	ft_remplir_stack_a(ac, av, &stack_a);
	stack = stack_a;
	ft_tab(&stack);
	if (ft_lstsize(stack_a) < 6)
	{
		if (ft_lstsize(stack_a) == 2)
			ft_sort_two(&stack_a);
		if (ft_lstsize(stack_a) == 3)
			ft_sort_three(&stack_a);
		if (ft_lstsize(stack_a) == 4)
			ft_sort_four(&stack_a, &stack_b);
		if (ft_lstsize(stack_a) == 5)
			ft_sort_five(&stack_a, &stack_b);
	}
	else
		sort_big_stack(&stack_a, &stack_b);
	return (0);
}	
