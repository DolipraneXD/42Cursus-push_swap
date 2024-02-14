/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:11 by moel-fat          #+#    #+#             */
/*   Updated: 2024/02/09 17:34:24 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libc.h>
# include "../libft/libft.h"

// **stack struct**
typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// **Parssing tools**
void		ft_print_err(void);
int			ft_check_int(char **args);
long int	ft_atoil(char *str);
int			check_dup(t_stack *stack, int nbr);

// **Rules**
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
// **Build Stack**
t_stack		*buildstack(int ac, char **av);
t_stack		*ft_lstnewstack(int data);
void		ft_lstadd_backstack(t_stack **lst, t_stack *new);
t_stack		*ft_lstlaststack(t_stack *lst);
int			ft_lstsizestack(t_stack *lst);
t_stack		*ft_lstbeforelast(t_stack *lst);
void		split_fill(t_stack **stack, char *av);
// **algo sort**
int			check_sorted(t_stack *stack);
void		push_swap(t_stack **a, t_stack **b, int stack_size);
void		three_sort(t_stack **stack);
int			highest_index(t_stack *stack);
void		full_sort(t_stack **a, t_stack **b);
void		get_t_pos(t_stack **a, t_stack **b);
void		get_position(t_stack **stack);
int			get_target(t_stack **a, int b_i, int target_i, int target_pos);
void		cost(t_stack **a, t_stack **b);
void		cheap_move(t_stack **a, t_stack **b);
void		move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		rotate_b(t_stack **b, int *cost_b);
void		rotate_a(t_stack **a, int *cost_a);
void		rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		r_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		shift_a(t_stack **a);
int			lowest_index_pos(t_stack **stack);
void		assing_index(t_stack *a, int s_size);
// **utils**
int			ft_abs(int nb);
void		ft_free(char **args);
void		free_stack(t_stack **stack);
void		free_everything(t_stack **a, t_stack **b);
void		check_space(char *str);
#endif