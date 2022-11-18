#include"get_next_line.h"

char *ft_firstl(char *buff)
{
	char *line;
	int len;
	int i;

	while(buff[i] && buff[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
int main()
{
	printf("%s","skkkds\ndjlslk;fs");
}