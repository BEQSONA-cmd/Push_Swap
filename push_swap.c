/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:48:27 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/04 19:34:20 by btvildia         ###   ########.fr       */
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

void	push_swap(char **av, int size)
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
	free(node.a);
	free(node.b);
}

void	one_arg(char *av)
{
	char	**c;
	int		i;

	i = 0;
	c = ft_split(av);
	while (c[i] != NULL)
		i++;
	push_swap(c, i);
}

int	main(int ac, char **av)
{
	int		i;
	char	**c;

	i = 1;
	if (ac == 2)
		one_arg(av[1]);
	else if (ac >= 3)
	{
		while (i < ac)
			i++;
		c = malloc(sizeof(char *) * i);
		i = 0;
		while (i < ac - 1)
		{
			c[i] = av[i + 1];
			i++;
		}
		push_swap(c, i);
		return (0);
	}
	else
		write(1, "\n", 1);
	return (0);
}
