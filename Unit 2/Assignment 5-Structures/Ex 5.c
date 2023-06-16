/*
 * Ex 5.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#define PI 3.1415
#define area(r)((PI)*(r)*(r))

void main()
{
	float radius,area;
	printf("Please enter the circle radius:");
	fflush(stdout);
	scanf("%f",&radius);
	printf("The circle area is %0.2f",area(radius));
}
