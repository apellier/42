#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	ret;

	while(lst != NULL)
	{
		lst = lst->next;
		ret++;
	}
	return (ret);
}