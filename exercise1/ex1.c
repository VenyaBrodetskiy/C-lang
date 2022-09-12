#include <stdio.h>

void ex1() {
	long int num1, num2, num3, sum;
	double average;

	printf("Input 1st integer: ");
	scanf_s("%d", &num1);

	printf("Input 2st integer: ");
	scanf_s("%d", &num2);

	printf("Input 3st integer: ");
	scanf_s("%d", &num3);

	sum = (num1 + num2 + num3);
	average = (double)sum / 3;

	printf("Sum of 3 integers is: %d", sum);
	printf("\nAverage of 3 int is: %.2f", average);
}

void ex2() {
	long int num1, num2, sum, dif1, dif2, prod;
	double divide1, divide2;

	printf("\nInput 1st integer: ");
	scanf_s("%d", &num1);

	printf("Input 2st integer: ");
	scanf_s("%d", &num2);

	sum = num1 + num2;
	dif1 = num1 - num2;
	dif2 = num2 - num1;
	prod = num1 * num2;
	divide1 = (double)num1 / num2;
	divide2 = (double)num2 / num1;

	printf("\nSum of 2 integers is: %d", sum);
	printf("\nDif 2nd - 1st is: %d", dif1);
	printf("\nDif 1st - 2nd is: %d", dif2);
	printf("\nMultiplication is: %d", prod);
	printf("\nDivide num1 / num2 is: %.2f", divide1);
	printf("\nDivide num2 / num1 is: %.2f\n", divide2);
}
