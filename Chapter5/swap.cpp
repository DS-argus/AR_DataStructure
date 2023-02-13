#include <iostream>

void swap(int* px, int* py){
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main(){
    int a = 1, b = 2;

    printf("before call swap function: a=%d, b=%d\n", a, b);

    swap(&a, &b);

    printf("after call swap function: a=%d, b=%d\n", a, b);

    return 0;
}