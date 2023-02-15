#include <iostream>
#include <stack>

double power(double x, int n){
    if (n == 0) return 1;

    if (n % 2 == 0){
        return power(x*x, n/2);
    }
    else{
        return x*power(x*x, (n-1)/2);    
    }  
}

int sum(int n){
    printf("%d\n", n);
    if (n<1) return 0;
    else return(n+sum(n-1));
}

void asterisk(int i){
    if (i > 1)
    {
        asterisk(i/2);
        asterisk(i/2);
    }
    printf("*");
    printf("\n");
}

int ex5(int n){
    if (n == 1) return 1;
    return n + ex5(n-1); 
}

float ex6(float n){
    if (n == 1) return 1;
    return 1/n + ex6(n-1); 
}

int Fibo(int n, int arr[]){
    arr[n]++;
    if(n==0){
        return 1;
    }else if(n==1){
        return 1;
    } 

    return  Fibo(n-2, arr) + Fibo(n-1, arr);
}

int main(){
    // double result = power(2.0, 100);
    // std::cout << result << std::endl;

    // std::cout << sum(5) << std::endl;

    // asterisk(5);

    // std::cout << ex5(2) << std::endl;
    // std::cout << ex6(3) << std::endl;

    int n = 3;
    int arr[4] = {0};

    Fibo(n, arr);

    for (int i = n; i >= 0; i--)
    {
        printf("Fibo(%d) = %dtimes\n", i, arr[i]);
    }    
}
