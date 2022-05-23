/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 03:16:07 by seyu              #+#    #+#             */
/*   Updated: 2021/05/24 01:34:46 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "sort.h"

static int
	partition(int arr[], int low, int high, int order)
{
	int	pivot;
	int	i;

	pivot = arr[high];
	i = low - 1;
	while (++i < high)
	{
		if (order == DESCENDING && arr[i] > pivot)
			swap(arr + low++, arr + i);
		else if (order == ASCENDING && arr[i] < pivot)
			swap(arr + low++, arr + i);
	}
	swap(arr + low, arr + high);
	return (low);
}

static void
	quick_sort_loop(int arr[], int low, int high, int order)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high, order);
		quick_sort_loop(arr, low, pi - 1, order);
		quick_sort_loop(arr, pi + 1, high, order);
	}
}

static void
	set_data_array(int **data_array, t_sort *sort)
{
	t_queue	*target_copy;
	int		itr;

	target_copy = copy_queue(sort->game->queue[sort->target - 1]);
	*data_array = ft_calloc(sort->size, sizeof(int));
	itr = -1;
	while (++itr < sort->size)
		reverse_pop_queue(target_copy, *data_array + sort->size - 1 - itr);
	delete_queue(&target_copy);
}

int	find_pivot(t_sort *sort, int *first_pivot, int *second_pivot, int order)
{
	int	*data_array;

	if (sort->size <= SPECIAL_QUICK_SIZE)
		return (FALSE);
	set_data_array(&data_array, sort);
	quick_sort_loop(data_array, 0, sort->size - 1, order);
	*first_pivot = data_array[(sort->size + 2) / 3 - 1];
	*second_pivot = data_array[(sort->size + 2) / 3 + sort->size / 3 - 1];
	free(data_array);
	return (TRUE);
}

int	number_of_unsorted(t_sort *sort)
{
	int	*data_array;
	int	*data_copy;
	int	itr;

	set_data_array(&data_array, sort);
	set_data_array(&data_copy, sort);
	quick_sort_loop(data_array, 0, sort->size - 1, sort->target == A);
	itr = -1;
	while (++itr < sort->size)
	{
		if (data_array[itr] != data_copy[itr])
			break ;
	}
	free(data_array);
	free(data_copy);
	return (sort->size - itr);
}
