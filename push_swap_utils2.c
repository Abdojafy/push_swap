/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:57:28 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 21:31:40 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b, int x)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (x == 0)
		ft_printf("rrr\n");
}

void	ft_check_overflow(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] == '0')
		j++;
	while (str[j])
	{
		i++;
		j++;
	}
	if (i > 12)
	{
		ft_printf("Erreur, Veuillez entrer que des entiers!");
		exit(0);
	}
}

void	ft_free_lstlast(t_list **lst)
{
	t_list	*temp;
	t_list	*p;

	if (lst)
	{
		p = (*lst);
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		temp = p->next;
		p->next = NULL;
		free(temp);
	}
}

int	*ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_tab(t_list **stack_a)
{
	int		i;
	int		size;
	int		*tab;
	t_list	*p;

	p = (*stack_a);
	size = ft_lstsize(p);
	tab = (int *) malloc (size * sizeof(int));
	if (!tab)
	{
		free(tab);
		exit(0);
	}
	i = 0;
	p = (*stack_a);
	while (p)
	{
		tab[i++] = p->content;
		p = p->next;
	}
	tab = ft_sort_tab(tab, i);
	ft_index(stack_a, tab, i);
	free(tab);
	free(p);
}
