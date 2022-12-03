#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//utils
int		get_index(char *str, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *nptr);

//main

char	*get_next_line(int fd);
char	*get_remainder(char *line, char *remainder_buffer);

#endif

