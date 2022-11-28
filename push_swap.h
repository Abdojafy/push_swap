/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:53:32 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 19:03:27 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include"ft_printf/libftprintf.h"
# include"Libft/libft.h"

void	sa(t_list **stack_a, int x);
void	sb(t_list **stack_b, int x);
void	ss(t_list **stack_a, t_list **stack_b, int x);
void	ra(t_list **stack_a, int x);
void	rb(t_list **stack_b, int x);
void	rr(t_list **stack_a, t_list **stack_b, int x);
void	rra(t_list **stack_a, int x);
void	rrb(t_list **stack_b, int x);
void	rrr(t_list **stack_a, t_list **stack_b, int x);
void	pb(t_list **stack_a, t_list **stack_b, int x);
void	pa(t_list **stack_a, t_list **stack_b, int x);

void	ft_small_stack(t_list **stack_a);
void	ft_check_args_numbers(int ac, char **av);
void	ft_check_duplicate(t_list *stack_a);

void	ft_check_overflow(char *str);
void	ft_sort_two(t_list **stack_a);
void	ft_sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_index(t_list **stack_a, int *tab, int size);
void	ft_free_lstlast(t_list **lst);
void	push(t_list **stack_e, t_list **stack_r);
int		get_index(t_list **stack_a, int indeex);
int		get_min(t_list **stack_a);
int		get_max(t_list **stack_a);
int		get_middle(t_list *stack_a);
void	ft_remplir_stack_a(int ac, char	**av, t_list **stack_a);

void	ft_find_min(t_list **stack_a);
void	ft_tab(t_list **stack_a);
void	sort_big_stack(t_list **stack_a, t_list **stack_b);
void	remplire_stack_b2(t_list **stack_a, t_list **stack_b, int i, int j);
void	remplire_stack_b(t_list **stack_a, t_list **stack_b);
void	remplire_stack_a(t_list **stack_a, t_list **stack_b);

#endif
