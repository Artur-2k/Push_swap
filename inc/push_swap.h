#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> // testing
#include <unistd.h> // write, read
#include <stdlib.h> // malloc, free, exit
#include <stdarg.h> // args
#include "../lib/Libft/libft.h" // libft

struct s_dlist
{
	struct s_dlist	*prev;
	int				num;
	struct s_dlist	*next;
};
typedef struct s_dlist	t_dlist;



#endif