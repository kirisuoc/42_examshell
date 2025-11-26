#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	len = 0;
	while (s[len])
		len++;
	return len;
}

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_swap(char *a, char *b)
{
	char	temp = *a;
	*a = *b;
	*b = temp;
}
int	ft_strchr(const char *s, char c)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return 0;
}

char	*order_string(char *s)
{
	int	len = ft_strlen(s);
	int	swapped = 1;


	while (swapped)
	{
		int	i = 0;
		swapped = 0;

		while (i < len - 1)
		{
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


void	generate_permutations(char *source, char *result, int pos)
{
	int	source_len = ft_strlen(source);

	// Caso base: permutación completa
	if (source_len == pos)
	{
		write(1, result, source_len);
		write(1, "\n", 1);
		return;
	}

	// Probar cada caracter de source
	int	i = 0;
	while (i < source_len)
	{
		if (!ft_strchr(result, source[i]))
		{
			result[pos] = source[i];	// Usar caracter
			generate_permutations(source, result, pos + 1);	// Recursar
			result[pos] = '\0';
		}
		i++;
	}


}


int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	if (ft_strlen(av[1]) == 0 || (av[1][0] == ' ' && !av[1][1]))
		return 0;

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
	return 0
}












/* int	main(void)
{
	char string[] = "azvcx";

	printf("String: %s\n", string);

	order_string(string);
	printf("String: %s\n", string);
	return 0;
}
 */
