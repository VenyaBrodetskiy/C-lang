#include <stdio.h>
#include <math.h>

void lection1part() {
	printf("hello world!\n");

	char c; // 1 byte
	unsigned char uc; // 1 byte
	short s; // 2 byte
	short int si; // 2 byte
	unsigned short us; // 2 byte
	unsigned short int usi; // 2 byte
	int i; // 2-4 bytes, usually 4. better specify is it short or long
	unsigned int ui; // 2-4 bytes, usually 4. better specify is it short or long
	long l; // 4 bytes
	long int li; // 4 bytes
	unsigned long int uli; // 4 bytes
	long long ll; // 8 bytes
	unsigned long long ull; // 8 bytes
	long long int lli; // 8 bytes
	unsigned long long int ulli; // 8 bytes

	float f; // 4 bytes flop
	double d; // 8 bytes flop
	long double ld; // 16 bytes or 12 bytes

	int num = 1;
	num++;
	scanf_s("%d", &num);
	printf("%d\n", num);

	int a1 = 1l;
	printf("cast as long int %d\n", a1);

	double d1 = 10e30;
	float f1 = d1;
	printf("double -> float %f\n", f1); // result: inf

	double d2 = 2.7;
	int myint = (int)(d2 + 0.5); // manually rounding number
	printf("manually round %d\n", myint);

	// let's make overflow

	unsigned short a, b, sum;
	a = 20000;
	b = 15000;
	sum = (a + b) * 2;
	printf("%d", sum); //wrong result, it's overflow (same logic as watch)

	printf("%d", sizeof(sum)); // sizeof returns
}

void lection2part() {
	int a, b, c;
	printf("Please enter 3 numbers: ");
	scanf_s("%d%d%d", &a, &b, &c);

	// preparation for mask
	typedef enum
	{
		MIDDLE = 0,
		UP = 1,
		LEFT = 2,
		RIGHT = 4,
		DOWN = 8,
		UP_LEFT = UP | LEFT
	} Direction;

	// make bit mask who is greater than whom
	Direction d =
		(a > b) * UP |
		(b >= a) * DOWN |
		(b > c) * LEFT |
		(c >= b) * RIGHT;

	2 | 5; // => 7. it's bitwise OR - result is 0. 101 or 010 = 111
	3 | 5; // => 7. 101 or 011 = 111
	3 || 5; // => 1. this is just OR, not by bit. So it's only 0 or 1. Statement same as True OR True => True => 1

	double x;
	printf("Enter a number: ");
	scanf_s("%lf", &x);
	printf("The round of a number is: %.3lf", round(x));
}


void main()
{
	/*printf("1st exercise: \n");
	ex1();

	printf("\n2nd exercise: ");
	ex2();*/

	lection2part();

}







// run program: ctrl + f5 or debug > start without debugging menu
// debug program: f5 or debug > start debugging menu

// tips for getting started: 
//   1. use the solution explorer window to add/manage files
//   2. use the team explorer window to connect to source control
//   3. use the output window to see build output and other messages
//   4. use the error list window to view errors
//   5. go to project > add new item to create new code files, or project > add existing item to add existing code files to the project
//   6. in the future, to open this project again, go to file > open > project and select the .sln file
