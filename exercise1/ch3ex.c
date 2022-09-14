#include <math.h>

void ch3ex1() {
	float x1, x2, y1, y2;
	float distance_pyf, distance_hypo;

	printf("Input x1, y1 coordinates: ");
	scanf_s("%f%f", &x1, &y1);
	
	printf("Input x2, y2 coordinates: ");
	scanf_s("%f%f", &x2, &y2);

	distance_pyf = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	distance_hypo = hypot((x2 - x1), (y2 - y1));

	printf("Distance by Pif formula = %f \n", distance_pyf);
	printf("Distance by Hypo formula = %f", distance_hypo);

}

void ch3ex2() {
	char letter_in_lower, result_in_upper;
	char letter_in_upper, result_in_lower;
	
	printf("Input character in lower case: ");
	scanf_s("%c", &letter_in_lower);

	getchar();

	result_in_upper = letter_in_lower - 32;
	printf("Character in upper case is: %c \n", result_in_upper);

	printf("Input character in upper case: ");
	scanf_s("%c", &letter_in_upper);

	result_in_lower = letter_in_upper + 32;
	printf("Character in upper case is: %c", result_in_lower);

}

void ch3ex3() {
	double f1;
	long round_f1;

	printf("Input variable: ");
	scanf_s("%lf", &f1);

	round_f1 = round(f1);
	printf("Rounded variable: %d", round_f1);

}


void ch3ex4() {
	double f1;
	long round_f1;

	printf("Input variable: ");
	scanf_s("%lf", &f1);

	round_f1 = round(f1);
	printf("Rounded variable: %d", round_f1);

}