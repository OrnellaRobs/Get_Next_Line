#include <stdio.h>

int	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int		main(void)
{
	const char *s = "hello\ncava";
	char c = '\n';
	printf("%s\n", ft_strchr(s, c));
	return 0;
}
