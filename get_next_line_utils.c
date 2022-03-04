#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	sym;

	i = 0;
	sym = (unsigned char) c;
	while (s[i] != '\0')
	{
		if (s[i] == sym)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == sym)
		return ((char *)(s + i));
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!(s))
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	min_len;

	if (!(s))
		return (0);
	min_len = ft_strlen(&s[start]);
	if (start >= ft_strlen(s))
		len = 0;
	else if (min_len < len)
		len = min_len;
	str = malloc(sizeof(*str) * (len + 1));
	if (!(str))
		return (0);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!(str))
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = src[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	j;
	size_t	i;
	char	*str;

	if (!(s1))
		return (0);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(str))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
