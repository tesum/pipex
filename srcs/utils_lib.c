#include "../pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (n > i)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_str;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len_str = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len_str + 1));
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[len_str] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s2 == 0)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i++] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	g;
	char	*s1;
	char	*str;

	if (s == NULL)
		return (0);
	s1 = (char *)s;
	i = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	g = 0;
	str = malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (0);
	while (len + start > i)
	{
		str[g] = s1[i];
		i++;
		g++;
	}
	str[g] = '\0';
	return (str);
}
