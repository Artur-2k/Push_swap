#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> // testing
#include <unistd.h> // write, read
#include <stdlib.h> // malloc, free, exit
#include <stdarg.h> // args
#include "../libft/libft.h" // libft

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

//*			PROTOTYPES   	*//


//*			LIST UTILS		*//
t_dlist *create_node(int num);
void	insert_at_head(t_stack *stack, int num);
void	push(t_stack *stack, int num);
void	pop(t_stack *stack);
void	remove_head(t_stack *stack);
void	swap_data(t_dlist **node1, t_dlist **node2);
void	update_index(t_stack *stack);
t_dlist	*get_smaller(t_stack stack);
t_dlist	*get_bigger(t_stack stack);
int 	is_sorted(t_stack stack);
void	free_list(t_dlist **head);
void	print_list(t_dlist *head);  //todo remove me

//*			Argument check	 *//

int *parse_arguments(int ac, char **av, int *count);


//* error managment and free resources   *//
void	error_exit(void);
void	error_exit_free(char **args, int *numbers);
void	ft_free_split(char **split);
void	free_list(t_dlist **head);

//*			Commands		 *//
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);


#endif