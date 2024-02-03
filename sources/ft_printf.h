/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:19 by btvildia          #+#    #+#             */
/*   Updated: 2024/02/03 20:25:38 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define PURPLE "\x1b[35m"

void	ft_error(char *a);
void	ft_putnbr(int nb);
int		ft_count(char *a);
void	ft_putchar(char a);
int		ft_strlen(char *a);
char	**ft_split(char *a);
int		ft_atoi(const char *str);
int		ft_find_char(int c, int i);
int		ft_ptr(uintptr_t nb, int j);
int		ft_find_str(char *a, int i);
int		ft_find_number(int n, int i);
int		ft_printf(const char *a, ...);
int		ft_find_hexup(size_t n, int i);
int		ft_find_hexlow(size_t n, int i);
int		ft_find_ptr(uintptr_t ptr, int j);
int		ft_find_uns(unsigned int n, int i);
char	*ft_strncpy(char *s1, char *s2, int n);
char	**ft_put(char **c, char *a, int i, int j);
int		ft_next_precent(const char *format, va_list args, int j, int i);

#endif
