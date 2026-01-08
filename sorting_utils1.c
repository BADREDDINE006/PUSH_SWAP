/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baharrou <baharrou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:39:50 by baharrou          #+#    #+#             */
/*   Updated: 2026/01/06 17:08:54 by baharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}

void	ft_find_target(t_list *stack_a, t_list *stack_b)
{
	long long	smallest;
	t_list		*best_target;
	t_list		*tmp;

	while (stack_b)
	{
		tmp = stack_a;
		smallest = LONG_MAX;
		best_target = NULL;
		while (tmp)
		{
			if (tmp->digit < smallest && tmp->digit > stack_b->digit)
			{
				smallest = tmp->digit;
				best_target = tmp;
			}
			tmp = tmp->next;
		}
		if (!best_target)
			stack_b->target = ft_min(stack_a);
		else
			stack_b->target = best_target;
		stack_b = stack_b->next;
	}
}

void	ft_calculate_cost(t_list *stack_a, t_list *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->index <= size_b / 2)
			stack_b->cost_b = stack_b->index;
		else
			stack_b->cost_b = size_b - stack_b->index;
		if (stack_b->target->index <= size_a / 2)
			stack_b->cost_a = stack_b->target->index;
		else
			stack_b->cost_a = size_a - stack_b->target->index;
		stack_b = stack_b->next;
	}
}

t_list	*ft_find_cheapest(t_list *stack_b)
{
	long long	cost;
	t_list		*cheapest;

	cost = LONG_MAX;
	cheapest = NULL;
	while (stack_b)
	{
		if (stack_b->cost_a + stack_b->cost_b < cost)
		{
			cost = stack_b->cost_a + stack_b->cost_b;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest);
}

int	ft_is_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->digit > stack_a->next->digit)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
