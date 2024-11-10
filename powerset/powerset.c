/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:16:51 by mkokorev          #+#    #+#             */
/*   Updated: 2024/11/10 15:16:51 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// docker run -it -v ${pwd}:/home/root ubuntu

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_parce(char **argv, int num, int *first)
{
	int	*arr;
	int	i;
	
	i = 0;
	arr = (int *)malloc(sizeof(int) * num);
	if (!arr)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return (NULL);
	}
	*first = atoi(argv[1]);
	while (i < num)
	{
		arr[i] = atoi(argv[i + 2]);
		i++;
	}
	return (arr);
}

void	ft_print_arr(int *arr, int num)
{
	int	i;
	
	i = 0;
	while (i < num)
	{
		fprintf(stdout, "arr: %d\n", arr[i]);
		i++;
	}
}

void	ft_print_arr_space(int *arr, int num)
{
	int	i;
	
	i = 0;
	while (i < num)
	{
		fprintf(stdout, "%d ", arr[i]);
		i++;
	}
}

int	ft_count_base_num(int idx, int *arr)
{
	int	i;
	int	base_num;
	
	i = 0;
	base_num = 0;
	while (i <= idx)
	{
		base_num = base_num + arr[i];
		i++;
	}
	return (base_num);
}

int	*ft_make_arr_base(int idx, int *arr)
{
	int	*arr_base;
	int	i;
	
	arr_base = (int *)malloc(sizeof(int) * (idx + 1));
	if (!arr)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return (NULL);
	}
	i = 0;
	while (i <= idx)
	{
		arr_base[i] = arr[i];
		i++;
	}
	return (arr_base);
}

void	ft_combinations(int idx, int num, int *arr, int first)
{
	int	i;
	int	base_num;
	int	*arr_base;
	int	sum;


	//if (idx == num - 1)
	//	return ;
	//ft_combinations(idx + 1, num, arr, first);
	if (arr[0] == first)
		fprintf(stdout, "%d\n", arr[0]);
	while (idx < num)
	{
		base_num = ft_count_base_num(idx, arr);
		//printf("base num : %d\n", base_num);
		arr_base = ft_make_arr_base(idx, arr);
		if (!arr_base)
			return ;
		//ft_print_arr(arr_base, idx + 1);
		i = idx + 1;
		while (i < num)
		{
			sum = base_num + arr[i];
			if (sum == first)
			{
				ft_print_arr_space(arr_base, idx + 1);
				fprintf(stdout, "%d\n", arr[i]);
			}
			sum = base_num - arr[i];
			i++;
		}
		free(arr_base);
		idx++;
	}
}

void	ft_backtrack(int idx, int num, int *arr, int first)
{
	ft_combinations(idx, num, arr, first);
}

int main (int argc, char **argv)
{
	int *arr;
	int num;
	int first;
	
	if (argc < 2)
	{
		fprintf(stdout, "put more arguments!\n");
		return (0);
	}
	num = argc - 2;
	arr = ft_parce(argv, num, &first);
	if (!arr)
		return (1);
	//fprintf(stdout, "first: %d\n", first);
	//ft_print_arr(arr, num);
	ft_backtrack(0, num, arr, first);
	return (1);
}
