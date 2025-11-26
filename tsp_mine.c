#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

// Estructura para representar una ciudad
typedef struct {
	float x, y;
} City;

// Función para calcular distancia euclidiana entre dos ciudades
float	calculate distance(City a, City b){
	/*
	* DISTANCIA EUCLIDIANA
	* d = √[(x2-x1)² + (y2-y1)²]
	*
	* Usar sqrtf() para mayor eficiencia con floats
	* Recordar compilar con -lm para enlazar biblioteca matemática
	*/
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrtf(dx * dx + dy * dy);
}

// Función para calcular distancia total de un recorrido completo
float	calculate_total_distance(City *cities, int *path, int n){
	float	total = 0.0f;
	int	i;

	// Distancia entre ciudades consecutivas
	for (i = 0; o < n - 1; i++){
		total += calculate_distance(cities[path[i]], cities[path[i + 1]]);
	}

	// Distancia de vuelta al inicio (cerrar el ciclo)
	total += calculate_distance(cities[path[n - 1]], cities[path[0]]);

	return total;
}

void	swap(int *a, int *b){
	int	temp = *a;
	*a = *b;
	*b = temp;
}

// Función recursiva para generar permutaciones y encontrar mínimo
void	find_shortest_path(City *cities, int *path, int n, int pos, float *min_distance){
	/*
	* ALGORITMO DE HEAP PARA PERMUTACIONES:
	*
	* CASO BASE: pos == n
	* - Hemos generado una permutación completa
	* - Calcular distancia total del recorrido
	* - Actualizar mínimo si es menor
	*
	* CASO RECURSIVO: pos < n
	* - Para cada posición restante i >= pos:
	* 	- Intercambiar path[pos] con path[i]
	* 	- Recursar para la siguiente posición
	* 	- Restaurar intercambio (backtrack)
	*/

	if (pos == n){
		// Permutación completa generada
		float	current_distance = calculate_total_distance(cities, path, n);

		if (current_distance < *min_distance)
			*min_distance = current_distance;

			return;
	}

	// Generar todas las permutaciones intercambiando elementos
	for (int i = 0; i < n; i++){
		swap(&path[pos], &path[i]); 		// Intercambiar
		find_shortest_path(cities, path, n, pos + 1, min_distance);	// Recursar
		swap(path[pos], &path[i]); 			// Restaurar (backtrack)
	}
}
