#define _GNU_SOURCE  // Para memmem()
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char *av)
{
	if (ac != 2 || av[1][0] == '\0')
		return 1;

	char temp[BUFFER_SIZE];
	char *result = NULL;
	char *buffer;
	int	total_read = 0;
	ssize_t bytes;

	// Leer de stdin hasta EOF
	while ((bytes = read(0, temp, BUFFER_SIZE)) > 0)
	{
		// Expandir el buffer principal para acomodar los nuevos datos
		buffer = realloc(result, total_read + bytes + 1);
		if (!buffer)
		{
			free(result);
			perror("realloc");
			return (1);
		}

		result = buffer;

		// Copiar los nuevos datos al buffer principal
		memmove(result + total_read, temp, bytes);
		total_read += bytes;
		result[total_read] = '\0' // Agregar terminación
	}

	// Verificar errores de lectura
	if (bytes < 0)
	{
		perror("read");
		free(result);
		return 1;
	}

	// Si no se leyó nada, salir sin error
	if (!result)
		return 0;

	// Procesar el buffer y aplicar el filtro
	ft_filter(result, av[1]);

	// Liberar memoria
	free(result);
	return 0;
}
