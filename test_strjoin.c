#include <stdio.h>
#include <stdlib.h>

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

	int		main(void)
	{
		char const *str = "bo";
		char const *buff = "nj";
		printf("%s\n", ft_strjoin(str, buff));
		return 0;
	}
