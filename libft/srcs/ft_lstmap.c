#include "../includes/libft.h"
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;

	ret = malloc(sizeof(t_list) * ft_lstsize(lst))
	if (!ret)
		return (NULL);
	
	while (lst->next != NULL)
	{
		lst->content = f(lst->content);
		ret->content = lst->content;
		ret->next = lst->next;
	}
	return(ret);
}