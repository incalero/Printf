#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (1 , &s[i++], 1);
}

int main(void)
{
	char	*c;
	c = "abcde";

	ft_putstr_fd(c);
	return(0);
	
	
}