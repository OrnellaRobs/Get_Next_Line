#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFF_SIZE 3

int		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*copy(char *str_both, char *s, int len_s, int j)
{
	int i;

	i = 0;
	while (i < len_s)
	{
		str_both[j] = s[i];
		i++;
		j++;
	}
	return (str_both);
}


char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		end;

	i = 0;
	str = (char *)s;
	end = ft_strlen(s);
	if (c == '\0')
		return (&str[end]);
	while ((char)str[i] != '\0')
	{
		if ((char)str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_both;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	j = 0;
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str_both = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1)))
		return (NULL);
	str_both = copy(str_both, (char *)s1, len_s1, j);
	j = len_s1;
	str_both = copy(str_both, (char *)s2, len_s2, j);
	j = (len_s1 + len_s2);
	str_both[j] = '\0';
	return (str_both);
}

int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char buff[BUFF_SIZE + 1];
	int read_octet;
	char *tmp;

	if (!fd)
		return (-1);
	while ((read_octet = read(fd, buff, BUFF_SIZE)) != 0 && (ft_strchr((const char *)buff, '\n') == 0))
	{
		buff[read_octet] = '\0';
		tmp = ft_strjoin((char const *)str, (char const *)buff);
		free(str);
		str = tmp;
	}
	printf("%s\n", str);
	return (0);
}

int		open_file(char const *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int		main(int argc, char const *argv[])
{
	int fd;
	int value;
	char *line;

	if ((fd = open_file(argv[1])) == -1)
		return (-1);
	value = get_next_line(fd, &line);
	return (0);
}
