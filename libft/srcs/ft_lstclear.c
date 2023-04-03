#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	
	while (*lst->next != NULL)
	{
		tmp = *lst;
		ft_lstdelone(lst, del);
		

	}
}