#include <stddef.h>
#include <stdlib.h>

int	get_index(char *str, char c)
{
	unsigned int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s) + 1;
	p = malloc(sizeof(char) * len);
	if (!p)
		return (0);
	ft_strlcpy(p, s, len);
	return (p);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	j = ft_strlcpy(&dst[i], src, dstsize - i);
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}

