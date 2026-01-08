/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baharrou <baharrou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:43:46 by baharrou          #+#    #+#             */
/*   Updated: 2026/01/07 14:45:31 by baharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse(char **av, t_list **stack_a)
{
	char	**args;
	int		j;
	int		i;

	i = 0;
	while (av[++i])
	{
		args = ft_split(av[i], ' ');
		if (!ft_isvalid(args))
			return (ft_free_all(args, *stack_a), 0);
		j = -1;
		while (args[++j])
			ft_lstadd_back(stack_a, ft_lstnew((int)ft_atol(args[j])));
		ft_free(args);
	}
	if (!ft_check_duplicate(*stack_a))
		return (ft_free_stack(*stack_a), 0);
	return (1);
}

static void	ft_prepare_to_pa(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;
	int		index_a;
	int		index_b;
	t_list	*cheapest;

	cheapest = ft_find_cheapest(*stack_b);
	if (!cheapest)
		return ;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	index_a = cheapest->target->index;
	index_b = cheapest->index;
	if (index_a <= size_a / 2 && index_b <= size_b / 2)
		ft_ft_rr(stack_a, stack_b, cheapest);
	else if (index_a > size_a / 2 && index_b > size_b / 2)
		ft_ft_rrr(stack_a, stack_b, cheapest);
	else
		ft_ra_rb(stack_a, stack_b, cheapest);
}

static void	ft_sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->digit;
	b = (*stack_a)->next->digit;
	c = (*stack_a)->next->next->digit;
	if (a > b && a > c)
		ra(stack_a);
	else if (b > a && b > c)
		rra(stack_a);
	a = (*stack_a)->digit;
	b = (*stack_a)->next->digit;
	if (a > b)
		sa(stack_a);
}

static void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	ft_push2b(stack_a, stack_b);
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_a == 2)
		sa(stack_a);
	else if (size_a >= 3)
		ft_sort_three(stack_a);
	while (size_b-- > 0)
	{
		ft_indexing(*stack_a);
		ft_indexing(*stack_b);
		ft_find_target(*stack_a, *stack_b);
		ft_calculate_cost(*stack_a, *stack_b);
		ft_prepare_to_pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*smallest;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!ft_parse(av, &stack_a))
		return (write(2, "Error\n", 6), 1);
	if (ft_is_sorted(stack_a))
		return (ft_free_stack(stack_a), 0);
	ft_sort(&stack_a, &stack_b);
	smallest = ft_min(stack_a);
	ft_indexing(stack_a);
	if (smallest->index <= ft_lstsize(stack_a) / 2)
		while (stack_a != smallest)
			ra(&stack_a);
	else
		while (stack_a != smallest)
			rra(&stack_a);
	ft_free_stack(stack_a);
	return (0);
}
