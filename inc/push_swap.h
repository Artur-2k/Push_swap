#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> // testing
#include <unistd.h> // write, read
#include <stdlib.h> // malloc, free, exit
#include <stdarg.h> // args
#include "../lib/libft/libft.h" // libft

struct s_dlist
{
	struct s_dlist	*prev;
	int				num;
	struct s_dlist	*next;
};
typedef struct s_dlist	t_dlist;

//*			PROTOTYPES   	*//

//*			LIST UTILS		*//
t_dlist *create_node(int num);
void	push(t_dlist **tail, t_dlist **head, int num);
void	insert_at_head(t_dlist **head,t_dlist **tail, int num);
void	pop(t_dlist **tail, t_dlist **head);
void	remove_head(t_dlist **head, t_dlist **tail);
void	swap_data(t_dlist **node1, t_dlist **node2);
void	free_list(t_dlist **head);
void	print_list(t_dlist *head);  //todo remove me

//*			Argument check	 *//

void	check_arguments(int ac, char **av);
long	get_valid_num(char *str);
void	perror_and_exit(void);

//*			Commands		 *//
void    sa(t_dlist **tail_a, t_dlist **tail_prev_a);
void    sb(t_dlist **tail_b, t_dlist **tail_prev_b);
void	ss(t_dlist **tail_a, t_dlist **tail_prev_a, t_dlist **tail_b, t_dlist **tail_prev_b);
void	pa(t_dlist **tail_a, t_dlist **head_a, t_dlist **tail_b, t_dlist **head_b);
void	pb(t_dlist **tail_b, t_dlist **head_b, t_dlist **tail_a, t_dlist **head_a);
void	ra(t_dlist **head_a, t_dlist **tail_a);
void	rb(t_dlist **head_b, t_dlist **tail_b);
void	rr(t_dlist **head_a, t_dlist **tail_a, t_dlist **head_b, t_dlist **tail_b);
void	rra(t_dlist **head_a, t_dlist **tail_a);
void	rrb(t_dlist **head_b, t_dlist **tail_b);
void	rrr(t_dlist **head_a, t_dlist **tail_a, t_dlist **head_b, t_dlist **tail_b);

#endif