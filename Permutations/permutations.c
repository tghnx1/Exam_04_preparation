/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_backtracking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:06:17 by mkokorev          #+#    #+#             */
/*   Updated: 2024/11/08 19:08:23 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_swap(char *str, int idx, int i)
{
	char	a;

	a = str[i];
	str[i] = str[idx];
	str[idx] = a;
	return (str);
}

void	ft_permutations(char *str, int len, int idx)
{
	int	i;

	if (idx == len - 1)
	{
		puts(str);
		return ;
	}
	i = idx;
	while (i < len)
	{
		str = ft_swap(str, idx, i);
		ft_permutations(str, len, idx + 1);
		str = ft_swap(str, idx, i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		puts("incorrect input");
		return (0);
	}
	len = ft_strlen(argv[1]);
	ft_permutations(argv[1], len, 0);
}
