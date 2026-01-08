/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baharrou <baharrou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:57:55 by baharrou          #+#    #+#             */
/*   Updated: 2026/01/06 17:09:08 by baharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				digit;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

//linked list manupilation functions
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list	*lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
// operations
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
//parsing utils
void	ft_free(char **str);
char	**ft_split(char *str, char sep);
long	ft_atol(char *str);
int		ft_isvalid(char **args);
int		ft_check_duplicate(t_list *stack_a);
void	ft_free_all(char **str, t_list *stack_a);
void	ft_free_stack(t_list *stack_a);
//sorting
void	ft_indexing(t_list *stack);
void	ft_find_target(t_list *stack_a, t_list *stack_b);
t_list	*ft_min(t_list *stack_a);
void	ft_calculate_cost(t_list *stack_a, t_list *stack_b);
t_list	*ft_find_cheapest(t_list *stack_b);
void	ft_push2b(t_list **stack_a, t_list **stack_b);
void	ft_ft_rr(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	ft_ft_rrr(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	ft_ra_rb(t_list **stack_a, t_list **stack_b, t_list *cheapest);
int		ft_is_sorted(t_list *stack_a);

#endif
