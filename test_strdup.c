#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		nb;

	nb = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

int	main(void)
{
	char **line;
	char *src;

	src = "bonjour\nnc";
	printf("%s\n", *line = ft_strdup((const char *)src));
	return 0;
}
