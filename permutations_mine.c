/*
* EJERCICIO: PERMUTATIONS
*
* DESCRIPCIÓN:
* Generar todas las permutaciones de un string dado en orden alfabético
*
* CONCEPTOS CLAVE:
* 1. BACKTRACKING: Algoritmo de exploración exhaustiva
* 2. ORDENAMIENTO: Asegurar orden alfabético
* 3. RECURSIÓN: Generar permutaciones nivel por nivel
* 4. ESTADO: Manejar qué caracteres ya se han usado
*
* ALGORITMO:
* 1. Ordenar el string original alfabéticamente
* 2. Para cada posición, probar cada carácter no usado
* 3. Marcar carácter como usado y recursar
* 4. Desmarcar carácter al retornar (backtrack)
* 5. Imprimir cuando se complete una permutación
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return i;
}

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strchr(const char *s, char c){
	int	 i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return 1; // Encontrado
		i++;
	}
	return 0; // No encontrado
}

// PARTE A APRENDER //

// Función para ordenar string alfabéticamente (bubble sort)
char	*order_string(char *s)
{
	/*
		ORDENAMIENTO MANUAL
		- Comparar caracteres adyacentes
		- Intercambiar si están en orden incorrecto
		- Repetir hasta que no haya intercambios
		- Garantiza orden alfabético para las permutaciones
	*/
/*
Va comparando desde el principio los caracteres adyacentes y los intercambia si el primero es mayor que el segundo.
Y así tantas veces como haga falta, desde el principio hasta el final. Cuando haya hecho una pasada sin intercambiar ninguno: swapped = 0,
termina y devuelve puntero al string (ya modificado)
*/

	int	len = ft_strlen(s);
	int	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		int	i = 0;

		while (i < len - 1){
			if (s[i] > s[i + 1])
			{
				ft_swap(&s[i], &s[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
	return s;
}

// Función recursiva para generar permutaciones
void	generate_permutations(char *source, char *result, int pos)
{
	/*
		ALGORITMO BACKTRACKING PARA PERMUTACIONES:

		CASO BASE: Si pos == longitud, tenemos una permutación completa
		- Imprimir la permutación actual
		- Retornar para probar otras opciones

		CASO RECURSIVO: Para cada carácter en source:
		- Si no está usado en result, probarlo
		- Agregarlo a result[pos]
		- Recursar para la siguiente posición
		- Remover carácter (backtrack) para probar otros
	*/

	int	source_len = ft_strlen(source);

	// Caso base: permutación completa
	if (pos == source_len)
	{
		write(1, result, source_len);
		write(1, "\n", 1);
		return;
	}

	// Probar cada caracter de source
	int	i = 0;
	while (i < source_len)
	{
		// Verificar si el caracter ya está usado
		if (!ft_strchr(result, source[i]))
		{
			result[pos] = source[i];		// Usar carácter
			generate_permutations(source, result, pos + 1);		// Recursar
			result[pos] = '\0';
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	/*
		VALIDACIÓN Y PROCESAMIENTO:
		- Verificar argumentos válidos
		- Validar que solo contiene letras
		- Ordenar string alfabéticamente
		- Inicializar buffer para resultado
		- Generar todas las permutaciones
	*/

	if (ac != 2)
		return 1;

	// Verificar string vacío o solo espacios
	if (ft_strlen(av[1]) == 0 || (av[1][0] == ' ' && !av[1][1]))
		return 0;

	// Validar que solo contiene caracteres alfabéticos
	int	i = 0;
	while (av[1][i])
	{
		if (!ft_isalpha(av[1][i]))
			return 0;
		i++;
	}


	int	len = ft_strlen(av[1]);

	// Alocar buffer para el resultado (permutación actual)
	char *result = calloc(len + 1, 1);
	if (!result)
	return 1;

	// Ordenar el string alfabéticamente
	char *source = order_string(av[1]);

	// Generar todas las permutaciones
	generate_permutations(source, result, 0);

	free(result);
	return 0;
}

















/* int	main(void)
{
	char string[] = "acbvaf";

	printf("String: %s\n", string);
	order_string(string);

	printf("String: %s\n", string);
	return 0;
} */

/* int	main(void)
{
	char a = 'a';
	char b = 'b';

	printf("A: %c\nB: %c\n", a, b);
	ft_swap(&a, &b);

	printf("A: %c\nB: %c\n", a, b);
	return 0;
}
 */
