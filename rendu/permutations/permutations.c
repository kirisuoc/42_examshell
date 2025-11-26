#include <stdio.h>

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

}
