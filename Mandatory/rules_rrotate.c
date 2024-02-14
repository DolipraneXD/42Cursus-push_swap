/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:56 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/08 16:11:16 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*bend;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	end = ft_lstlaststack(*stack);
	bend = ft_lstbeforelast(*stack);
	tmp = *stack;
	*stack = end;
	(*stack)->next = tmp;
	bend->next = NULL;
}

void	rra(t_stack **a)
{
	r_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
