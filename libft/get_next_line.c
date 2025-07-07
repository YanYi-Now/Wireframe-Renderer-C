#include "libft.h"

int	contains_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int		br;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br == -1)
		{
			if (save)
				free(save);
			free(buffer);
			return (NULL);
		}
		if (br == 0)
			break ;
		buffer[br] = '\0';
		save = ft_strjoin(save, buffer);
		if (contains_newline(buffer))
			break ;
	}
	free(buffer);
	return (save);
}

char	*clean_line(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (i)
	{
		line[j] = save[j];
		j++;
		i--;
	}
	line[j] = '\0';
	return (line);
}

char	*left_over(char *save)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save[i + 1])
	{
		free(save);
		return (NULL);
	}
	i++;
	temp = (char *)malloc((sizeof(char) * (ft_strlen(save) - i + 1)));
	if (!temp)
	{
		free(save);
		return (NULL);
	}
	j = 0;
	while (save[i])
		temp[j++] = save[i++];
	temp[j] = '\0';
	free(save);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = clean_line(save);
	save = left_over(save);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    int i = 1;
    while (i <= 10)
    {
        char *str = get_next_line(fd);
        printf("%d: %s", i, str);
        i++;
    }
    if (fd != -1)
    	close(fd);
    return (0);
}
*/
