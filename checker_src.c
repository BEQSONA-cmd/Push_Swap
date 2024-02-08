/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:53:51 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/08 20:55:29 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_node *a, int size)
{
	if (if_sorted(a->a, a->a_size, 0) != 0)
		return ;
	else
	{
		if (size == 2)
			s_a(a);
		else if (size == 3)
			sort_3a(a);
		else
			quicksort_a(a, size, 0);
	}
}

int	*push_swap(char **av, int size)
{
	int		i;
	t_node	node;

	i = 0;
	node.a = malloc(sizeof(int) * size);
	node.b = malloc(sizeof(int) * size);
	node.a_size = size;
	node.b_size = 0;
	while (i < size)
	{
		node.a[i] = ft_atoi(av[i]);
		i++;
	}
	if_doubles(node.a, size);
	sorting(&node, size);
	free(node.b);
	return (node.a);
}

void	one_arg(char *av)
{
	char	**c;
	int		i;
	int		*x;

	i = 0;
	c = ft_split(av);
	while (c[i] != NULL)
		i++;
	x = push_swap(c, i);
	i = 0;
	while (c[i] != NULL)
	{
		free(c[i]);
		i++;
	}
	free(x);
	free(c);
}
