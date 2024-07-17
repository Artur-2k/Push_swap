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
void insert_at_head(t_dlist **head,t_dlist **tail, int num);
void insert_at_tail(t_dlist **tail, t_dlist **head, int num);
void pop(t_dlist **tail, t_dlist **head);
void swap_data(t_dlist **node1, t_dlist **node2);
void free_list(t_dlist **head);
void print_list(t_dlist *head);  //todo remove me

//*			Argument check	 *//

void	check_arguments(int ac, char **av);
long	get_valid_num(char *str);
void	perror_and_exit(void);



#endif