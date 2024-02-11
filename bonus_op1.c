/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:38:43 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/11 20:07:30 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_s_a(t_node *node)
{
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = 0;
	i = node->a[0];
	node->a[0] = node->a[1];
	node->a[1] = i;
}

void	b_p_a(t_node *node)
{
	int	i;

	if (node->b_size)
	{
		node->a_size++;
		i = node->a_size;
		while (--i > 0)
			node->a[i] = node->a[i - 1];
		node->a[0] = node->b[0];
		i = -1;
		node->b_size--;
		while (++i < node->b_size)
			node->b[i] = node->b[i + 1];
	}
	else
		return ;
}

void	b_r_a(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = 0;
	j = node->a[i];
	i++;
	while (i < node->a_size)
	{
		node->a[i - 1] = node->a[i];
		i++;
	}
	node->a[i - 1] = j;
}

void	b_r_r_a(t_node *node)
{
	int	j;
	int	i;

	if (node->a_size == 0 || node->a_size == 1)
		return ;
	i = node->a_size - 1;
	j = node->a[i];
	while (i)
	{
		node->a[i] = node->a[i - 1];
		i--;
	}
	node->a[i] = j;
}

void	b_s_s(t_node *node)
{
	int	j;

	if (node->a_size == 0 || node->a_size == 1 || (node->b_size == 0
			|| node->b_size == 1))
		return ;
	j = 0;
	j = node->a[0];
	node->a[0] = node->a[1];
	node->a[1] = j;
	j = node->b[0];
	node->b[0] = node->b[1];
	node->b[1] = j;
}
