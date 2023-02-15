#include <iostream>

// int move = 0;
int hanoiTower(int n, char from, char tmp, char to){

    if(n==1) return 1;

    else{
        return hanoiTower(n-1, from, to, tmp) + 
                hanoiTower(1, from, tmp, to) + 
                hanoiTower(n-1, tmp, from, to);
    }


}

int main(){
    int result = hanoiTower(10, '1', '2', '3');
    std::cout << result << std::endl;
}