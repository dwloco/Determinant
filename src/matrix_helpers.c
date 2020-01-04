/*
 * matrix_helpers.c
 *
 *  Created on: Jan 3, 2020
 *      Author: Trotsky
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_helpers.h"


void fill_matrix(int n, float *m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("Ingrese el valor [%d, %d] de la matriz: ", i, j);
			scanf("%f", &m[i*n + j]);
		}
	}
}


void print_matrix(int n, float* m) {
	for (int i = 0; i < n; i++) {
		printf("[");
		for (int j = 0; j < n; j++) {
			printf("%f ", m[i*n + j]);
		}
		printf("]\n");
	}
}


void get_min(int x, int y, Mat m, Mat* new_m, float *ptrM) {
	int iContRow, iContCol;

	new_m->n = m.n - 1;
	new_m->m = ptrM;

	iContRow = 0;
	iContCol = 0;
	for (int i = 0; i < m.n; i++) {
		if (i != y) {
			for (int j = 0; j < m.n; j++) {
				if (j != x) {
					if (iContRow < new_m->n) { //Se ejecuta en las filas 1 - n
						new_m->m[iContCol*new_m->n + iContRow] = m.m[i*m.n + j];
						iContRow++;
					} else { // Se ejecuta para el primer elementos de cada fila
						iContRow = 0;
						if (iContCol < new_m->n) {
							iContCol++;
							new_m->m[iContCol*new_m->n + iContRow] = m.m[i*m.n + j];
							iContRow++;
						}
					}
				}
			}
		}
	}
}


float det(Mat matrix) {
	float fDet = 0;
	float *m = matrix.m;

	if (matrix.n == 1) {
		fDet = m[0];
	} else if (matrix.n == 2) {
		fDet = m[0]*m[3] - m[1]*m[2];
	} else if (matrix.n > 2) {
		fDet = 0;
		for (int j = 0; j < matrix.n; j++) {
			Mat mAux;
			float ptrM[matrix.n-1][matrix.n-1];
			get_min(j, 0, matrix, &mAux, (float*) ptrM);
			fDet += pow(-1, j)*matrix.m[j]*det(mAux);
		}
	}
	return fDet;
}
