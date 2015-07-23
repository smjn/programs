#include <stdio.h>

void dummy();
void sub();
void bye();


void test() {
	printf("Test");
	printf("Test2");
	//sub();
	//dummy();
	//bye();
}
//void test() {
//	printf("Test");
//	printf("Test2");
//	//dummy();
//	//bye();
//}

void sub() {
	printf("sub");
	test();
}

void dummy() {
	printf("Hello");
	printf("World");
	//main();
	sub();
}

void bye() {
	printf("Bye");
	sub();
}

int main() {

	dummy();
	bye();
	dummy();
	return 0;
}

