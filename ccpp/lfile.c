#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd;
	if((fd=creat("testf",0666))==-1)
		perror("cannot create!");
	else
		fprintf(stdout, "created!");

	close(fd);
	if((fd=open("testf",O_WRONLY,0))==-1)
		perror("cannot open");
	else
		fprintf(stdout, "opened");
	char *txt = "hello world";
	write(fd, txt, strnlen(txt,100));
	close(fd);
	
	return 0;
}

