/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:42 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/08 15:33:12 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_bonus(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (*from == NULL)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}

void	pa_bonus(t_stack **a, t_stack **b)
{
	push_bonus(b, a);
}

void	pb_bonus(t_stack **a, t_stack **b)
{
	push_bonus(a, b);
}
