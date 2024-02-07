/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:20:16 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/07 14:25:24 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_error(char *a)
{
	ft_printf("%s\n", a);
	exit(1);
}

int	ft_count(char *a)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		if (a[i])
			j++;
		while (a[i] && a[i] != ' ')
			i++;
	}
	return (j);
}

char	**ft_put(char **c, char *a, int i, int j)
{
	int	x;

	x = 0;
	while (a[i])
	{
		while (a[i] && a[i] == ' ')
			i++;
		j = i;
		while (a[i] && a[i] != ' ')
			i++;
		if (i > j)
		{
			c[x] = malloc(sizeof(char) * (i - j) + 1);
			ft_strncpy(c[x], &a[j], i - j);
			x++;
		}
	}
	c[x] = NULL;
	return (c);
}

char	**ft_split(char *a)
{
	int		i;
	int		j;
	char	**c;

	i = 0;
	j = ft_count(a);
	c = malloc(sizeof(char *) * j + 1);
	i = 0;
	j = 0;
	c = ft_put(c, a, i, j);
	return (c);
}
