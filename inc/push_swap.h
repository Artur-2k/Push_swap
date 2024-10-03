/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:13 by artuda-s          #+#    #+#             */
/*   Updated: 2024/10/03 12:46:14 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // testing
# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free, exit
# include <stdarg.h> // args
# include "../libft/libft.h" // libft

typedef struct s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	struct s_dlist	*target;
	int				num;
	int				above_medium;
	int				index;
	int				cost;
	int				rot_both;
}	t_dlist;

typedef struct s_stack
{
	int		size;
	t_dlist	*head;
	t_dlist	*tail;
}	t_stack;

/*************************************************************************/
//*			PROTOTYPES			*//
//*			LIST UTILS			*//
t_dlist	*get_smaller(t_stack stack);
t_dlist	*get_bigger(t_stack stack);
t_dlist	*create_node(int num);
int		is_sorted(t_stack stack);
void	update_index(t_stack *stack);
void	swap_data(t_dlist **node1, t_dlist **node2);
void	push(t_stack *stack, int num);
void	pop(t_stack *stack);
void	insert_at_head(t_stack *stack, int num);
void	remove_head(t_stack *stack);

//*			Argument check		*//
int		*parse_arguments(int ac, char **av, int *count);

//*			Error and recourses	*//
void	error_exit(void);
void	error_exit_free(char **args, int *numbers, int need_free);
void	ft_free_split(char **split);
void	free_list(t_dlist **head);
void	free_last_resources(int *numbers, t_dlist *head_a, t_dlist *head_b);

//*			Commands			*//
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//*			Algorithms			*//
void	turk_algorithm(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);

//*			Targets				*//
t_dlist	*find_target_a(t_stack stack_b, int num);
t_dlist	*find_target_b(t_stack stack_a, t_dlist node);

//*			Cheapest			*//
t_dlist	*find_cheapest_a(t_stack *stack_a, t_stack *stack_b);

//*			Topping targets		*//
void	place_at_top(t_stack *stk_a, t_stack *stk_b, t_dlist cheap, \
					t_dlist targ);
void	place_target_a_at_top(t_stack *stack_a, t_dlist target);
/*************************************************************************/

#endif
