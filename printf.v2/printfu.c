#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	mostr_exad (const void *ptr)
{
	char str[16];  // Buffer para almacenar la dirección en formato hexadecimal
    unsigned long long direccion;
	char	*p;

	p = "0123456789abcdef";
	direccion = (unsigned long long)ptr;
	int indice = sizeof(str) -1;
	str[indice] = '\0';

	while (indice > 0 && direccion > 0) 
	{
        indice--;
    	str[indice] = p[direccion % 16];
        direccion /= 16;
    }
	if (indice >= 2) 
	{
        str[indice - 1] = 'x';
        str[indice - 2] = '0';
        indice -= 2;
    }
	write(1, str + indice, sizeof(str) - indice);

}

int	main(void)
{
	char	*u;
	
	u = ("12el puerto de maroto");
	mostr_exad(u);
	printf("\nel string a estudio es: %s\n", u);
	printf("la direccion de memoria de u es: %p\n", (unsigned int *)u);
	return(0);
}