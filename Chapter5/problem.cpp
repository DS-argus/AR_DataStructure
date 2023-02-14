#include <iostream>

void sub(int b[]){
    b[0] = 0;
}
int main(){
    // int i = 10;
    // int* p;
    // p = &i;
    // *p = 8;

    // printf("%d", i);

    int a[] = {1, 2, 3, 4, 5, 6};
    sub(a);
    printf("%d\n", a[0]);

}