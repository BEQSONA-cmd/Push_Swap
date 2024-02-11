/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:24:26 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/11 19:19:44 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_node *node, int len, int witch)
{
	if (witch == 0)
		p_b(node);
	else
		p_a(node);
	len--;
	return (len);
}

void	error(int *a)
{
	free(a);
	ft_printf("Error\n");
	exit(1);
}

void	if_doubles(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (a[i] == a[j])
				error(a);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	if_sorted(int *a, int size, int order)
{
	int	i;

	i = 1;
	if (order == 0)
	{
		while (i < size)
		{
			if (a[i - 1] > a[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < size)
		{
			if (a[i - 1] < a[i])
				return (0);
			i++;
		}
		return (1);
	}
}
