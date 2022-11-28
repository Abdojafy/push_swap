/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:40:22 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 21:36:50 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	get_middle(t_list *stack_a)
{
	t_list	*temp;
	t_list	*tempnext;

	if (ft_lstsize(stack_a) % 2 == 0)
		return (ft_lstsize(stack_a) / 2);
	temp = stack_a;
	tempnext = stack_a;
	while (temp->next)
	{
		temp = temp->next->next;
		tempnext = tempnext->next;
	}
	return (tempnext->index);
}

void	ft_check_duplicate(t_list *stack_a)
{
	t_list	*current;

	while (stack_a)
	{
		current = stack_a;
		while (stack_a->next)
		{
			if (current->content == stack_a->next->content)
			{
				ft_printf("Veuillez entrer des nombres differents!");
				exit(0);
			}
			stack_a = stack_a->next;
		}
		stack_a = current->next;
	}
}

void	ft_check_args_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] > 47 && av[i][j] < 58)
				break ;
			j++;
		}
		if (av[i][j] == '\0')
		{
			ft_printf("Error");
			exit(0);
		}
		j = 0;
		i++;
	}
}

void	ft_free_tab(char **p, int tab)
{
	int	i;

	i = 0;
	while (i <= tab)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	ft_remplir_stack_a(int ac, char	**av, t_list **stack_a)
{
	t_list	*lst;
	char	*str_join;
	char	**str;
	int		i;

	i = 1;
	str_join = ft_strdup("");
	while (av[i])
		str_join = ft_strjoin(str_join, av[i++]);
	str = ft_split(str_join, ' ');
	i = 0;
	while (str[i])
	{
		ft_check_overflow(str[i]);
		lst = ft_lstnew(ft_atoi(str[i]), 0);
		ft_lstadd_back(stack_a, lst);
		lst = NULL;
		i++;
	}
	ft_free_tab(str, i);
	free(str_join);
	free(lst);
	ft_check_duplicate(*stack_a);
	ft_check_args_numbers(ac, av);
}
