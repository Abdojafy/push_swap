/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:03:56 by ajafy             #+#    #+#             */
/*   Updated: 2022/06/14 19:17:31 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		moins;
	long	res;

	i = 0;
	moins = 0;
	res = 0;
	if ((str[i]) && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			moins++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (moins == 1)
		res = -res;
	if (str[i] || res > 2147483647 || res < -2147483648)
	{
		ft_printf("Erreur, Veuillez entrer que des entiers!");
		exit(0);
	}
	return ((int)res);
}
