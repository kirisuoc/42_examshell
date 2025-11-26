#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *s){
	int	i = 0;
	while (s[i])
		i++;
	return i;
}

int	is_alpha(char c){
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = *a;
}

int	ft_strchr(const char *s, char c){
	int	i = 0;

	while (s[i]){
		if (c == s[i])
			return 1;
		i++;
	}
	return 0;
}

char *order_string(char *s){
	// ORDENAMIENTO BURBUJA
	int	len = ft_strlen(s);
	int	swapped = 1;

	while (swapped){
		swapped = 0;
		int	i = 0;

		while (i < len - 1){
			if (s[i] > s[i + 1]){
				ft_swap(&s[i], &s[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
	return s;
}

// Función recursiva para generar permutaciones
void	generate_permutations(char *source, char *result, int pos){
	int	source_len = ft_strlen(source);

	// Caso base: permutación completa
	if (pos == source_len){
		write(1, result, source_len);
		write(1, "\n", 1);
		return;
	}

	// Probar cada carácter de source
	int	i = 0;
	while (i < source_len){
		// Verificar si el carácter ya está usado
		if (!ft_strchr(result, source[i])){
			result[pos] = source[i];		// Usar carácter
			generate_permutations(source, result, pos + 1); 	// Recursar
			result[pos] = '\0';				// Backtrack: remover carácter
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	// Verificar string vacío o solo espacios
	if (ft_strlen(av[1]) == 0 || (av[1][0] == ' ' && !av[1][1]))
		return 0;

	// Validar que solo contiene carácteres alfabéticos
	int	i = 0;
	while (av[1][i]){
		if (!is_alpha(av[1][i]))
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
