// compile with -D BUFFERSIZE= [number]
// avoid to define the buffer size in .c file

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i = 0;
	char	*dest;

	
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	int		bytes;
	int		i = 0;
	char	character;
	char	buffer[BUFFER_SIZE+1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);

	bytes = read(fd, &character, 1);

	while (bytes > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, 1);
	}

	if (bytes <= 0 && i == 0)
		return (NULL);

	buffer[i] = '\0';

	return (ft_strdup(buffer));
}
