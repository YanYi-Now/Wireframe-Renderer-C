#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		contains_newline(char *buffer);
char	*ft_read(int fd, char *save);
char	*clean_line(char *save);
char	*left_over(char *save);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *save, char *buffer);
int		ft_atoi(const char *str);

#endif
