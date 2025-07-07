#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *save, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc(sizeof(char) * \
					(ft_strlen(save)+ ft_strlen(buffer) + 1));
	if (!new)
	{
		if (save)
			free(save);
		return (0);
	}
	i = 0;
	j = 0;
	while (save && save[i])
	{
		new[i] = save[i];
		i++;
	}
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(save);
	return (new);
}
