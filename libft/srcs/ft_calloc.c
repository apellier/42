#include "../includes/libft.h"
void	*calloc (size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0 || nmemb > INT_MAX / size)
		return(NULL);	
	result = malloc(sizeof(size) * nmemb);
	if (!result)
		return (NULL);
	return (result);
}