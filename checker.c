/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:16:01 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 18:51:55 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	ft_check_name(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a, 1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b, 1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a, 1);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b, 1);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a, 1);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b, 1);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b, 1);
	else
		ft_error();
}

void	ft_check_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (*stack_b)
	{
		ft_printf("KO\n");
		exit(0);
	}
	while (*stack_a)
	{
		if ((*stack_a)->index != i)
		{
			ft_printf("KO\n");
			exit(0);
		}
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	ft_printf("OK\n");
	exit(0);
}

int	main(int ac, char *av[])
{
	char	str[1024];
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_remplir_stack_a(ac, av, &stack_a);
		stack = stack_a;
		ft_tab(&stack);
		while (read(0, str, 1024))
		{
			ft_check_name(str, &stack_a, &stack_b);
			ft_bzero(str, 1024);
		}
	}
	ft_check_sort(&stack_a, &stack_b);
}
