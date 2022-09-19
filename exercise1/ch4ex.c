void ch4ex1() {
	float
		rect_x1 = 4,
		rect_x2 = 7,
		rect_y1 = 2,
		rect_y2 = 8;
	float x, y;

	printf("Please input x and y coordinates:");
	scanf_s("%f%f", &x, &y);

	if (rect_x1 < x && x < rect_x2 && rect_y1 < y && y < rect_y2)
		printf("Dot is inside rectangle");
	else
		printf("Not inside rectangle");

}

void ch4ex2() {
	int a, b;
	printf("Please input 2 int numbers:");
	scanf_s("%d%d", &a, &b);

	// (a > b) ? printf("max is: %d", a) : printf("max is: %d", b);
	printf("max is %d", (a > b) ? a : b);

}

void ch4ex3() {
	int a, b, c;
	printf("Please input 3 int numbers:");
	scanf_s("%d%d%d", &a, &b, &c);
	int ab, bc, ac;
	ab = a > b;
	bc = b > c;
	ac = a > c;

	if (ab && ac) printf("max: %d", a);
	if (bc && !ab) printf("max: %d", b);
	if (!ac && !bc) printf("max: %d", c);
}

void ch4ex5() {
	char ch1,ch2;

	// 1st easy option
	//printf("Please input hexadecimal number:");
	//scanf_s("%x", &n);
	//printf("output %d", n);
	// it was too easy


	// 2nd option ->

	printf("Please input hexadecimal number:");
	scanf_s("%c%c", &ch1, 1, &ch2, 1); 
	// why don't work?? Ask Alon
	//ch1 = getchar();
	//ch2 = getchar();

	int n1, n2;

	if (48 <= ch1 && ch1 <= 57) {
		n1 = ch1 - '0';
	} 
	else {
		n1 = ch1 - 'A' + 10;
	}

	if (48 <= ch2 && ch2 <= 57) {
		n2 = ch2 - '0';
	}
	else {
		n2 = ch2 - 'A' + 10;
	}

	printf("input %d %d, output %d", n1, n2, n1*16 + n2);
}

void ch4ex6() {
	int n;
	printf("Please input month number:");
	scanf_s("%d", &n);

	switch (n) {
		case 1:
			printf("Jan");
			break;
		case 2:
			printf("Feb");
			break;
		case 3:
			printf("March");
			break;
		case 4:
			printf("April");
			break;
		default:
			printf("not implemented");
	}
}