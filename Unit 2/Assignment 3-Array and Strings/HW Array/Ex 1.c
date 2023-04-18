/*
 * Ex 1.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#include <stdlib.h>

void main() {
	float m1[2][2], m2[2][2];

	printf("Enter the elements of the first matrix\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("Enter a%d%d: ", i + 1, j + 1);
			fflush(stdout);
			fflush(stdin);
			scanf("%f", &m1[i][j]);
		}
	}

	printf("Enter the elements of the second matrix\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("Enter a%d%d: ", i + 1, j + 1);
			fflush(stdout);
			fflush(stdin);
			scanf("%f", &m2[i][j]);
		}
	}

	printf("Sum of Matrix:\n");

	for(int i=0 ; i<2 ; i++){
		for(int j=0 ; j<2 ; j++){
			printf("%.2f\t",m1[i][j]+m2[i][j]);
		}
		printf("\n");
	}

}

