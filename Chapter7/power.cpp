#include <iostream>
#include <stack>
#include <vector>

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

long Fibolong(int n){
    std::vector<long> result;

    for (int i = 0; i < n; i++)
    {
        if(i==0) {
            result.push_back(1);
        }
        else if (i==1){
            result.push_back(1);
        }
        else {
            result.push_back(result[i-1] + result[i-2]);
        }

        if (result.back() < 0) {
            std::cout << "Maximum n : " << i << std::endl;
            return result[i-1];
         }
    }
    std::cout << "Not yet" << std::endl;
    return result.back();
}

void reverse(const char* word){
    int len = strnlen(word, 100);
    char result[len];

    for (int i = 0; i < len; i++)
    {   
        result[len-1-i] = word[i];
    }

    std::cout << result << std::endl;
}

int Ackermann(int m, int n){
    if (m==0)
    {
        return 1;
    }else if(m==1 && n==0){
        return 2;
    }else if(m>1 && n==0){
        return m+2;
    }else{
        return Ackermann(Ackermann(m-1, n), n-1);
    }
}

void draw_tree(int row, int left, int right){
    if (row==4)
    {
        return;
    }
    
    int l = right-left+1;

    for (int j = 0; j < power(2,row); j++)
    {
        for (int i = 1; i <= l; i++)
        {
            if(i == l/2){
                printf("X");
            }else{
                printf("-");
            }
        }
    }
    printf("\n");
    draw_tree(row+1, left, l/2);
}


int main(){
    draw_tree(0, 1, 40);
}
