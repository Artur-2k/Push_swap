#include "../inc/push_swap.h"

t_dlist *create_node(int num)
{
	t_dlist *new_node = (t_dlist*)malloc(sizeof(t_dlist));
	if (!new_node)
		return (ft_printf("Malloc error!\n"), NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->num = num;
	return (new_node);
}
void insert_at_head(t_dlist **head,t_dlist **tail, int num)
{
	t_dlist *new_node = create_node(num); // allocates memory for the new node
	if (*head)
	{
		new_node->next = (*head);
		(*head)->prev = new_node;
		*head = new_node;
	}
	else
	{
		*head = new_node;
		*tail = new_node;
	}
}
void insert_at_tail(t_dlist **tail, t_dlist **head, int num)
{
	t_dlist *new_node = create_node(num);

	if (*tail)
	{
		(*tail)->next = new_node;
		new_node->prev = *tail;
		*tail = new_node;
	}
	else
	{
		*head = new_node;
		*tail = new_node;
	}
}
void free_list(t_dlist **head)
{
//					   temp
//			  head
//	NULL <-> data1 <-> data2 <-> data3 <-> NULL
	t_dlist *temp = NULL;

	while ((*head)->next != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	free(*head);
}
void pop_tail(t_dlist **tail, t_dlist **head)
{
//   		  head
//		         	  tail
//	NULL <- data1 <-> data2  -> NULL
	t_dlist *preview = (*tail)->prev;

	if ((*tail)->prev != NULL)
	{
		preview = (*tail)->prev;
		free(*tail);
		preview->next = NULL;
		*tail = preview;
	}
	else
	{
		free(*tail);
		*head = NULL;
		*tail = NULL;
	}
}
void swap_data(t_dlist **node1, t_dlist **node2)
{
	int temp;

	temp = (*node1)->num;
	(*node1)->num = (*node2)->num;
	(*node2)->num = temp;
}



void print_list(t_dlist *head) {
    t_dlist *current = head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");  // Print a newline at the end
}

int main(int ac, char** av)
{
    t_dlist *head = NULL;
    t_dlist *tail = NULL;


	free_list(&head);

    return 0;
}