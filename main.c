#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 8
#endif

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return i;
}
int main(int argc, char **argv)
{

	int fd = open(argv[1], O_RDWR | O_APPEND | O_CREAT | O_TRUNC, 0644);
	ssize_t bytes;
	char *buf;
	bytes = 1;
	write(fd, argv[2], ft_strlen(argv[2]));
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	
	while(bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		printf("buffer -> %s\n", buf);
	}

	(void)argc;
	return 0;
}	

/*


you should add some edits tho.
- take file name as param ==> if file does not exist, create it
*/