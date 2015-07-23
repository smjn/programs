#include <stdio.h>
int main(void){
	int factorial = 1, num, i;
	printf("Enter some shit");
	scanf("%d",&num);

	for(i = 1; i <= num; i++){
		factorial *= i;
	}

	printf("factorial is %d\n", factorial);
	return 0;
}
