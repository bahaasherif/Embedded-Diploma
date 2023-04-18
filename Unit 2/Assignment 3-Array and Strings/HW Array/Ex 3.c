/*
 * Ex 3.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int r,c;
	printf("Enter rows and column of matrix: ");
	fflush(stdout); fflush(stdin);
	scanf("%d %d",&r,&c);

	float a[r][c];

	printf("enter elements of matrix:\n");
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
			printf("enter element m%d%d: ",i+1,j+1);
			fflush(stdout); fflush(stdin);
			scanf("%f",&a[i][j]);
		}
	}

	printf("entered matrix: \n");
	for(int i=0 ; i<r ; i++){
		for( int j=0 ; j<c ; j++){
			printf("%.1f\t",a[i][j]);
		}
		printf("\n");
	}

	printf("transpose of matrix: \n");
	for(int i=0 ; i<c ; i++){
			for( int j=0 ; j<r ; j++){
				printf("%.1f\t",a[j][i]);
			}
			printf("\n");
		}
}


