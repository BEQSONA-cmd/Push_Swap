/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:53:51 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/11 20:06:22 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_errors(t_node *node)
{
	free(node->a);
	free(node->b);
	ft_printf("Error\n");
	exit(1);
}

void	sorting(t_node *a, int size)
{
	if (if_sorted(a->a, size, 0) != 0)
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

void	b_r_r_r(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1 || (node->b_size == 0
			|| node->b_size == 1))
		return ;
	i = node->a_size - 1;
	j = node->a[i];
	while (i)
	{
		node->a[i] = node->a[i - 1];
		i--;
	}
	node->a[i] = j;
	i = node->b_size - 1;
	j = node->b[i];
	while (i)
	{
		node->b[i] = node->b[i - 1];
		i--;
	}
	node->b[i] = j;
}
