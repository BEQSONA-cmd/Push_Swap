/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:03:54 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/04 15:24:38 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_b(t_node *node)
{
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = 0;
	i = node->b[0];
	node->b[0] = node->b[1];
	node->b[1] = i;
	ft_printf("sb\n");
}

void	p_b(t_node *node)
{
	int	i;

	if (node->a_size)
	{
		node->b_size++;
		i = node->b_size;
		while (i > 0)
		{
			node->b[i] = node->b[i - 1];
			i--;
		}
		node->b[0] = node->a[0];
		i = 0;
		node->a_size--;
		while (i < node->a_size)
		{
			node->a[i] = node->a[i + 1];
			i++;
		}
		ft_printf("pb\n");
	}
	else
		return ;
}

void	r_b(t_node *node)
{
	int	j;
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = 0;
	j = node->b[i];
	i++;
	while (i < node->b_size)
	{
		node->b[i - 1] = node->b[i];
		i++;
	}
	node->b[i - 1] = j;
	ft_printf("rb\n");
}

void	r_r_b(t_node *node)
{
	int	tmp;
	int	i;

	if (node->b_size == 0 || node->b_size == 1)
		return ;
	i = node->b_size - 1;
	tmp = node->b[i];
	while (i)
	{
		node->b[i] = node->b[i - 1];
		i--;
	}
	node->b[i] = tmp;
	ft_printf("rrb\n");
}

void	r_r(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1 || (node->b_size == 0
			|| node->b_size == 1))
		return ;
	i = 0;
	j = node->a[i];
	while (i < node->a_size)
	{
		node->a[i - 1] = node->a[i];
		i++;
	}
	node->a[i - 1] = j;
	i = 0;
	j = node->b[i];
	while (i < node->b_size)
	{
		node->b[i - 1] = node->b[i];
		i++;
	}
	node->b[i - 1] = j;
	ft_printf("rr\n");
}
