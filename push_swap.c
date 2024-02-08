/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:48:27 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/08 20:55:38 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**c;
	int		*x;

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
		x = push_swap(c, i);
		free(x);
		free(c);
		return (0);
	}
	return (0);
}
