#include "get_next_line.h"

char	*ft_getline(char **s, int rs)
{
	int		i;
	char	*res;
	char	*tmp;

	i = 0;
	while ((*s)[i] != '\0' && (*s)[i] != '\n')
		i++;
	res = ft_substr(*s, 0, i + 1);
	if ((*s)[i] == '\n')
		tmp = ft_strdup(&((*s)[i + 1]));
	else
		tmp = 0;
	free(*s);
	*s = tmp;
	if (rs > 0 || i > 0)
		return (res);
	free(res);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int			rs;

	rs = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!(save))
		save = ft_strdup("\0");
	while (!(ft_strchr(save, '\n')) && rs != 0)
	{
		rs = read(fd, buf, BUFFER_SIZE);
		if (rs == -1)
			return (0);
		buf[rs] = '\0';
		save = ft_strjoin(save, buf);
	}
	return (ft_getline(&save, rs));
}
