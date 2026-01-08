/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baharrou <baharrou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:33:40 by baharrou          #+#    #+#             */
/*   Updated: 2026/01/06 15:48:12 by baharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_tab(t_list *stack_a, int *arr, int size_a)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (stack_a)
	{
		arr[i++] = stack_a->digit;
		stack_a = stack_a->next;
	}
	i = -1;
	while (++i < size_a - 1)
	{
		j = -1;
		while (++j < size_a - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return (arr[size_a / 2]);
}

void	ft_push2b(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	*arr;
	int	pivot;

	size_a = ft_lstsize(*stack_a);
	arr = malloc(size_a * sizeof(int));
	if (!arr)
		return ;
	pivot = ft_sort_tab((*stack_a), arr, size_a);
	while (size_a-- > 3)
	{
		if ((*stack_a)->digit > pivot)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			pb(stack_a, stack_b);
	}
	free(arr);
}

void	ft_ft_rr(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	int	i;
	int	remainder;

	i = 0;
	remainder = cheapest->cost_a - cheapest->cost_b;
	if (cheapest->cost_a - cheapest->cost_b >= 0)
		while (i++ < cheapest->cost_b)
			rr(stack_a, stack_b);
	else
		while (i++ < cheapest->cost_a)
			rr(stack_a, stack_b);
	i = 0;
	if (remainder > 0)
		while (i++ < remainder)
			ra(stack_a);
	else
		while (i++ < (remainder * (-1)))
			rb(stack_b);
}

void	ft_ft_rrr(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	int	i;
	int	remainder;

	i = 0;
	remainder = cheapest->cost_a - cheapest->cost_b;
	if (cheapest->cost_a - cheapest->cost_b >= 0)
		while (i++ < cheapest->cost_b)
			rrr(stack_a, stack_b);
	else
		while (i++ < cheapest->cost_a)
			rrr(stack_a, stack_b);
	i = 0;
	if (remainder > 0)
		while (i++ < remainder)
			rra(stack_a);
	else
		while (i++ < (remainder * (-1)))
			rrb(stack_b);
}

void	ft_ra_rb(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	int	i;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (cheapest->index <= size_b / 2 && cheapest->target->index > size_a / 2)
	{
		i = 0;
		while (i++ < cheapest->cost_a)
			rra(stack_a);
		i = 0;
		while (i++ < cheapest->cost_b)
			rb(stack_b);
	}
	else
	{
		i = 0;
		while (i++ < cheapest->cost_a)
			ra(stack_a);
		i = 0;
		while (i++ < cheapest->cost_b)
			rrb(stack_b);
	}
}
