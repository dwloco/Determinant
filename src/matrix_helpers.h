/*
 * matrix_helpers.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Trotsky
 */

#ifndef MATRIX_HELPERS_H_
#define MATRIX_HELPERS_H_

typedef struct {
	float* m; //Matriz
	int n; //De nxn
} Mat;

void fill_matrix(int, float*); //Llena la matriz
void print_matrix(int, float*); //Muestra la matriz x pantalla
void get_min(int, int, Mat, Mat*); //Devuelve la matriz recortada x referencia
float cofactor(int, int, float);
float det(Mat); //Calcula el determinante de la matriz

#endif /* MATRIX_HELPERS_H_ */
