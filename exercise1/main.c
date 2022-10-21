#include <stdio.h>

void lection1part() {
	//printf("hello world!\n");

	//char c; // 1 byte
	//unsigned char uc; // 1 byte
	//short s; // 2 byte
	//short int si; // 2 byte
	//unsigned short us; // 2 byte
	//unsigned short int usi; // 2 byte
	//int i; // 2-4 bytes, usually 4. better specify is it short or long
	//unsigned int ui; // 2-4 bytes, usually 4. better specify is it short or long
	//long l; // 4 bytes
	//long int li; // 4 bytes
	//unsigned long int uli; // 4 bytes
	//long long ll; // 8 bytes
	//unsigned long long ull; // 8 bytes
	//long long int lli; // 8 bytes
	//unsigned long long int ulli; // 8 bytes

	//float f; // 4 bytes flop
	//double d; // 8 bytes flop
	//long double ld; // 16 bytes or 12 bytes

	//int num = 1;
	//num++;
	//scanf_s("%d", &num);
	//printf("%d\n", num);

	//int a1 = 1l;
	//printf("cast as long int %d\n", a1);

	//double d1 = 10e30;
	//float f1 = d1;
	//printf("double -> float %f\n", f1); // result: inf

	//double d2 = 2.7;
	//int myint = (int)(d2 + 0.5); // manually rounding number
	//printf("manually round %d\n", myint);

	//// let's make overflow

	//unsigned short a, b, sum;
	//a = 20000;
	//b = 15000;
	//sum = (a + b) * 2;
	//printf("%d", sum); //wrong result, it's overflow (same logic as watch)

	//printf("%ud", sizeof(sum)); // sizeof returns
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

void lection_ch_3() {
	int i, c;

	printf("Enter =>");
	
	c = getchar();
	fflush(stdin);
	i = c - '0';

	printf("The ASCII code of the c is: %d \n", c);
	printf("The value of the digit is: %d \n", i);

}

void lection_ch7_pointers() {
	int i = 6;
	int x = 7;

	int* p = &i;
	printf("How to see what's in i var 1) %d 2) %d \n", i, *p);

	p = &x;
	printf("How to see what's in x var 1) %d 2) %d", x, *p);
}

void lection_ch7_pointers_to_arrya() {
	int a[10];
	int* p = a; // it make p and a point to same place in memory. no need &a, because a is already a pointer
	int* p1 = &a[0]; // other way to point to array
	*(p + 1) = 4; // it puts 4 in a[1]

}

void lection_ch8() {
	int a[10];
	int* p = a; // p points to same location
	++p;
	int r = p == &a[1]; // r equals 1 (true)

	r = p[1] == a[2]; // r equals 1 (true) because p is pointer and this is same as array!
	printf("what's insade r: %d", r);
}

// write a function that swap 2 varible without creating new
void swap(int* a, int* b) {
	*a = *b + *a;
	*b = *a - *b;
	*a = *a - *b;
}

void lection_ch9_dynamic_alloc() {
	printf("Enter N of elements of array \n");
	int n;
	scanf_s("%d", &n);
	
	// this approach just will not compile
	// int a[n];
	// because we cannot dynamically allocate memory such way. we need to use alloc functions
	// int a[10] only works with const 

	// allocate 10 elements int array
	int* p = (int*)malloc(n * sizeof(int));
	// in p we will have garbage
	memset(p, 0, n * sizeof(int)); // puts 0 in memory of p array


	// allocate and clear n of element array
	int* cp = calloc(n, sizeof(int));
	// in cp we will have 0 in each array member

	free(p);
	free(cp);
} 

void lection_ch9_enum() {
	enum day_of_week {Sunday, Monday};

	enum day_of_week day;
	day = Sunday;

	printf("%d", day); // => 0
}


void lection_ch10_struct() {

	typedef unsigned char byte;
	// 1. create new struct
	struct RGB
	{
		byte red;
		byte green;
		byte blue;
	};
	// make variable a which is struct
	struct RGB a = {1, 1, 1};

	// 2. create struct and alias it with name rgb_type
	typedef struct
	{
		byte red;
		byte green;
		byte blue;
	} rgb_type;
	// make variable b, which is struct
	rgb_type b = { 1, 1, 1 };

	// 3. other (strange) way to make both struct and type of this struct
	typedef struct RGB_strange
	{
		byte red;
		byte green;
		byte blue;
	} rgb_strange_type;
	// now we can use both ways to define struct.
	// using struct
	struct RGB_strange c = {1, 1, 1};
	// using type
	rgb_strange_type c1 = {1, 1, 1};

	// 4. access to property of struct
	// 1st way
	byte red = c.red;

	// 2nd way with pointer;
	rgb_strange_type* pointer_c = &c;
	byte red1 = pointer_c->red;
}

void lection_ch10_linked_list_of_struct() {
	typedef unsigned char byte;
	typedef struct RGB
	{
		byte red;
		byte green;
		byte blue;
		struct RGB* nextPtr;
	} rgb_type;

	rgb_type a, b, c;
	a.nextPtr = &b;
	b.nextPtr = &c;
	c.nextPtr = NULL;
	// now we have linked structs a --> b --> c --> nothing

	rgb_type* pointer = &a;
	// let's set c.blue to 5
	pointer->nextPtr->nextPtr->blue = 5;
	printf("%d", c.blue); // 5
}

void lection_ch10_unions() {
	// better to avoid unions basically

	typedef unsigned char byte;
	typedef enum { red, green, blue, alpha } color_type;
	typedef union RGB
	{
		int color;
		byte color_parts[4];
	} rgb_type;

	rgb_type pixel; 
	pixel.color = 255 + (128 << 8) + 0;

	printf("The components of lught purple are: [%d, %d, %d, %d]", pixel.color_parts[red], pixel.color_parts[green], pixel.color_parts[blue], pixel.color_parts[alpha]);
	// color_parts[0] will be 255, color parts[1] will be 128 even though we didn't put there any number. because it access same memory
	
	pixel.color_parts[0] = 100;
	printf("%d", pixel.color); // will shot 4 bytes, 1st 8 bits will be 100
}

typedef char* my_string;
void swap_of_strings(my_string* a, my_string* b) {
	my_string temp = *a;
	*a = *b;
	*b = temp;
}

int fileToUpperCase()
{
	char file_name[50];
	char file_content[1000][1000];

	printf("Write is 1st file name: ");
	scanf_s("%s", file_name, sizeof(file_name));

	char file_name_output[50];
	printf("\nWrite is 2nd file name: ");
	scanf_s("%s", file_name_output, sizeof(file_name_output));

	FILE* old_file = NULL;
	errno_t err = fopen_s(&old_file, file_name, "r");

	FILE* new_file = NULL;
	errno_t err2 = fopen_s(&new_file, file_name_output, "w");

	if (err || err2)
		printf_s("\nThe file was not opened\n");
	else
	{
		int i_line = 0;
		while (!feof(old_file))
		{
			fgets(file_content[i_line], sizeof(file_content[i_line]), old_file);
			printf("File content is: %s\n", file_content[i_line]);

			int i_char = 0;
			while (file_content[i_line][i_char] != '\0')
			{
				if (file_content[i_line][i_char] <= 122 && file_content[i_line][i_char] >= 97)
					file_content[i_line][i_char] -= 32;
				i_char++;
			}
			printf("File content after UPPERize is: %s", file_content[i_line]);
			fputs(file_content, new_file);
		}
		fclose(new_file);
		fclose(old_file);
	}
	
}

int fileToUpperCaseBinaryFile()
{
	char file_name[50];
	char file_content[1000];

	//FILE* create_file = NULL;
	//errno_t err0 = fopen_s(&create_file, file_name, "w");
	//if (err0)
	//	printf_s("\nThe file was not opened\n");
	//else
	//{
	//	char str_init[100] = "Some content in Upper and lower CASE \n new lINE content";
	//	fwrite(str_init, sizeof(char), sizeof(str_init), create_file);
	//	fclose(create_file);
	//}

	printf("Write is 1st file name: ");
	scanf_s("%s", file_name, sizeof(file_name));

	char file_name_output[50];
	printf("\nWrite is 2nd file name: ");
	scanf_s("%s", file_name_output, sizeof(file_name_output));

	FILE* old_file = NULL;
	errno_t err1 = fopen_s(&old_file, file_name, "r");
	
	FILE* new_file = NULL;
	errno_t err2 = fopen_s(&new_file, file_name_output, "w"); 

	if (err1 || err2)
		printf_s("\nThe file fscanf.out was not opened\n");
	else
	{
		// before doing ftell need to move cursor in file to the end
		int filesize = ftell(old_file);
		fread(file_content, sizeof(char), 100, old_file);
		printf("File content is:\n%s\n", file_content);

		int i_char = 0;
		while (file_content[i_char] != '\0')
		{
			if (file_content[i_char] <= 122 && file_content[i_char] >= 97)
				file_content[i_char] -= 32;
			i_char++;
		}
		printf("File content after UPPERize is: %s", file_content);
		fwrite(file_content, sizeof(char), sizeof(file_content), new_file);

		fclose(old_file);
		fclose(new_file);
	}

}

void main()
{
	//fileToUpperCase();
	fileToUpperCaseBinaryFile();
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
