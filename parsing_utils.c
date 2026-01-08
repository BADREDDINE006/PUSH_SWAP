/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baharrou <baharrou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:08:57 by baharrou          #+#    #+#             */
/*   Updated: 2026/01/03 14:49:54 by baharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isvalid(char **args)
{
	int		i;
	long	num;

	if (!args || !(*args))
		return (0);
	i = -1;
	while (args[++i])
	{
		if (!ft_isdigit(args[i]))
			return (0);
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
	}
	return (1);
}

int	ft_check_duplicate(t_list *stack_a)
{
	int		num;
	t_list	*ptr;

	while (stack_a)
	{
		num = stack_a->digit;
		ptr = stack_a;
		while (ptr)
		{
			ptr = ptr->next;
			if (ptr && num == ptr->digit)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
