#include <stdlib.h>

typedef	struct s_list
{
	int	c;
	struct s_list *next;
} t_list;

int	main()
{
	t_list	*head;

	head = NULL;
	head = malloc(sizeof(t_list) * 1);
	head->next = malloc(sizeof(t_list) * 1);
	head->next->next = malloc(sizeof(t_list) * 1);
	head->next->next->next = malloc(sizeof(t_list) * 1);
	system("leaks a.out");
	exit(0);
}