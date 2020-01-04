/*
 ============================================================================
 Name        : Determinant.c
 Author      : Trotsky
 Version     : 1.0
 Description : Matrix determinant calculator
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_helpers.h"

int main(void) {
	int N;
	float fDeterm;

	do {
		printf("Ingrese la cantidad de filas/columnas de la matriz cuadrada: ");
		scanf("%d", &N);
		if (N < 2) {
			printf("Por favor asegurese que el tamaño de la matriz sea mayor o igual a 2x2\n");
		}
	} while (N < 2);

	float matrix[N][N];
	fill_matrix(N, (float*) matrix); //Cargado de la matriz
	print_matrix(N, (float*) matrix); //Muestra de la matriz x pantalla

	Mat mat;
	mat.m = (float*) matrix;
	mat.n = N;

	fDeterm = det(mat);
	printf("El determinante de la matriz ingresada es %lf", fDeterm);
	return 0;
}


