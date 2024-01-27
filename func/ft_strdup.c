
#include "../include/pipex.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t		i;

	i = 0;
	ptr = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}