/*
 * Output
 *  Function x:4 lines
	Function y:7 lines
	Function z:Recursion
	/usr/lib/x86_64-linux-gnu/crt1.o: In function `_start':
	(.text+0x20): undefined reference to `main'
	collect2: error: ld returned 1 exit status
 */

void x(){
	int y=10;
	int k=5;
	k++;
}

int y(){
	int a=0;
	int b=1;
	int c=4;
	return a+b+c;
}

int z(){
	z();
}
