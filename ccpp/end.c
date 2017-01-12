#include<stdio.h>

int main(){
    char *p = NULL;
    int a = 512;
    char b = 'a';
    p = (char *)(&a);
    printf("%x\n",&a);
	return 0;
}
