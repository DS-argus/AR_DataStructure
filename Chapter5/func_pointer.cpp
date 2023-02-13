#include <iostream>

void foo(int a){
    printf("foo : %d\n", a);
}

int main(){
    void (*f)(int);

    f = foo;
    f(10);      // == foo(10)
    (*f)(20);   // == f(10)

    return 0;
}


