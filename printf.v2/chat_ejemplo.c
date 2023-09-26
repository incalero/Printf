#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void mostr_exad(const void *ptr) 
{
    char str[20];  
    unsigned long long direccion;

    direccion = (unsigned long long)ptr;
    int indice = sizeof(str) - 1;
    str[indice] = '\0';
	
    while (indice > 1 && direccion > 0) {
        indice--;
        str[indice] = "0123456789abcdef"[direccion % 16];
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

int main(void) {
    char *u = "12el puerto de maroto"; 

    printf("el string a estudio es: %s\n", u);
    printf("la direccion de memoria de u es: %p\n", (void *)u);
    mostr_exad(u);  // Llamamos a mostr_exad después de printf para que muestre la dirección en formato deseado
    printf("\n");
    return 0;
}