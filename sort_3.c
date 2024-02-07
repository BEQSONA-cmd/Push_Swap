/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:13:05 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/07 15:31:25 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3a(t_node *node)
{
	if (node->a[0] > node->a[1] && node->a[0] > node->a[2]
		&& node->a[1] > node->a[2])
	{
		s_a(node);
		r_r_a(node);
	}
	if (node->a[0] > node->a[1] && node->a[0] > node->a[2]
		&& node->a[1] < node->a[2])
	{
		r_a(node);
	}
	if (node->a[0] > node->a[1] && node->a[0] < node->a[2]
		&& node->a[1] < node->a[2])
	{
		s_a(node);
	}
	if (node->a[0] < node->a[1] && node->a[0] < node->a[2]
		&& node->a[1] > node->a[2])
	{
		s_a(node);
		r_a(node);
	}
	if (node->a[0] < node->a[1] && node->a[0] > node->a[2]
		&& node->a[1] > node->a[2])
		r_r_a(node);
}

int	sort_3b(t_node *node, int len)
{
	if (len == 1)
		p_a(node);
	else if (len == 2)
	{
		if (node->b[0] < node->b[1])
			s_b(node);
		while (len--)
			p_a(node);
	}
	else if (len == 3)
	{
		while (len || !(node->a[0] < node->a[1] && node->a[1] < node->a[2]))
		{
			if (len == 1 && node->a[0] > node->a[1])
				s_a(node);
			else if (len == 1 || (len >= 2 && node->b[0] > node->b[1])
				|| (len == 3 && node->b[0] > node->b[2]))
				len = ft_push(node, len, 1);
			else
				s_b(node);
		}
	}
	return (0);
}

void	sort_3ab(t_node *node, int len)
{
	if (len == 3 && node->a_size == 3)
		sort_3a(node);
	else if (len == 2 && (node->a[0] > node->a[1]))
		s_a(node);
	else if (len == 3)
	{
		while (len != 3 || !(node->a[0] < node->a[1]
				&& node->a[1] < node->a[2]))
		{
			if (len == 3 && node->a[0] > node->a[1] && node->a[2])
				s_a(node);
			else if (len == 3 && !(node->a[2] > node->a[0]
					&& node->a[2] > node->a[1]))
				len = ft_push(node, len, 0);
			else if (node->a[0] > node->a[1])
				s_a(node);
			else if (len)
			{
				p_a(node);
				len++;
			}
		}
	}
}
