#include<stdio.h>

void p();
void q();
void r();

void r(){
    q();
}

void q(){
    printf("hello");
    r();
}

void p(){
    //p();
}

int main(){
    p();
    q();
    r();
    return 0;
}
