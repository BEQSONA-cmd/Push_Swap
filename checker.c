/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:48:27 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/11 20:05:30 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_swap(t_node *node, char *c)
{
	if (ft_strcmp(c, "sa\n") == 0)
		b_s_a(node);
	else if (ft_strcmp(c, "sb\n") == 0)
		b_s_b(node);
	else if (ft_strcmp(c, "ss\n") == 0)
		b_s_s(node);
	else if (ft_strcmp(c, "ra\n") == 0)
		b_r_a(node);
	else if (ft_strcmp(c, "rb\n") == 0)
		b_r_b(node);
	else if (ft_strcmp(c, "rr\n") == 0)
		b_r_r(node);
	else if (ft_strcmp(c, "rra\n") == 0)
		b_r_r_a(node);
	else if (ft_strcmp(c, "rrb\n") == 0)
		b_r_r_b(node);
	else if (ft_strcmp(c, "rrr\n") == 0)
		b_r_r_r(node);
	else if (ft_strcmp(c, "pa\n") == 0)
		b_p_a(node);
	else if (ft_strcmp(c, "pb\n") == 0)
		b_p_b(node);
	else
		ft_errors(node);
}

int	check_free(int *x, int size)
{
	int	i;

	i = 0;
	while (x[i])
		i++;
	if (i == size)
		return (0);
	else
		return (1);
}

void	put_swap(t_node *node)
{
	char	*c;

	while (1)
	{
		c = get_next_line(0);
		if (ft_strcmp(c, "\n") == 0)
			break ;
		make_swap(node, c);
		free(c);
	}
}

void	check_swap(char **c, int size)
{
	t_node	node;
	int		i;

	i = 0;
	node.a = malloc(sizeof(int) * size);
	node.b = malloc(sizeof(int) * size);
	if (node.a == NULL || node.b == NULL)
		ft_errors(&node);
	node.a_size = size;
	node.b_size = 0;
	while (i < size)
	{
		node.a[i] = ft_atoi(c[i]);
		i++;
	}
	if_doubles(node.a, size);
	put_swap(&node);
	i = 0;
	if (if_sorted(node.a, size, 0) != 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(node.a);
	free(node.b);
}

int	main(int ac, char **av)
{
	int		i;
	char	**c;

	c = malloc(sizeof(char *) * ac);
	i = 0;
	if (ac == 2)
	{
		i = ft_count(av[1]);
		c = ft_split(av[1]);
		check_swap(c, i);
	}
	else if (ac >= 3)
	{
		if (c == NULL)
			ft_error("Error");
		while (i < ac - 1)
		{
			c[i] = av[i + 1];
			i++;
		}
		c[i] = NULL;
		check_swap(c, i);
	}
	free(c);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	char	**c;
// 	int		i;

// 	i = 0;
// 	c = malloc(sizeof(char *));
// 	if (ac >= 2)
// 	{
// 		while (1)
// 		{
// 			c[i] = get_next_line(0);
// 			if (strcmp(c[i], "\n") == 0)
// 				break ;
// 			i++;
// 		}
// 		i = 1;
// 		while (c[i - 1] != NULL)
// 		{
// 			if ((ft_strcmp(c[i - 1], ft_strjoin(av[i], "\n")) == 0) && av[i
// 				+ 1] == NULL && ft_strcmp(c[i], "\n") == 0)
// 			{
// 				ft_printf("OK\n");
// 				free(c);
// 				return (0);
// 			}
// 			if ((ft_strcmp(c[i - 1], ft_strjoin(av[i], "\n")) != 0) || av[i
// 				+ 1] == NULL)
// 			{
// 				ft_printf("KO\n");
// 				free(c);
// 				return (0);
// 			}
// 			i++;
// 		}
// 		ft_printf("OK\n");
// 	}
// 	return (0);
// }
