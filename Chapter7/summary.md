Chapter 7. 순환(recursion)
===============
----
* 순환
    * 함수를 호출할 때마다 stack의 활성 레코드(activation record)에 저장되어 recursion 가능
    * ==순환 멈추는 부분 + 순환 호출하는 부분== 으로 구성
        * 일부는 해결하고 남아있는 부분을 순환시키는 것(**==Divide and conquer==**)
        ```C++
        int factorial(int n)
        {
            if(n==1) return 1;
            else return (n * factorial(n-1));   // 꼬리순환
            else return (factorial(n-1) * n);   // 머리순환
            // n이 해결된 부분, factorial(n-1)이 남아있는 부분
        }
        ```
        * 문제의 크기가 점점 작아짐
    * for loop, while 같은 반복 알고리즘과 기능 유사
        * *꼬리순환*의 경우 쉽게 반복 형태로 변경가능
        * *머리순환*은 쉽지 않음 ex) 하노이의 탑
        * 전반적으로 순환은 더 간단하게 구현 가능하지만 함수 호출 때문에 느려지는 경향
        
    * 대표적인 예시
    1. 팩토리얼
    2. 거듭제곱
        * x^n^ = x^2*(n/2)^ 형태 이용
    3. 피보나치
        * `return fibo(n-2) + fibo(n-1)` 꼴은 호출이 너무 늘어나 느려짐
        * 배열에 값을 저장해놓는 형태로 해야 빠름(동적프로그래밍?)
    4. 하노이의 탑
        * `hanoi.cpp` 참고

---
* 다중 순환 : **하나의 함수에서 2개 이상의 순환 호출이 이루어지는 경우**
    * 선형 순환 : 1개만 호출됨
    * 예시 : 피보나치수열, 하노이의 탑
    * 영상채색 : 흰 화소를 만나면 색칠하고 이웃한 네 방향의 이웃화소에 대해 순환적으로 검사
        * `ConnectedComponent.cpp` 참고
    
---
* 연습문제
1. 문제가 작아지지 않음 `return n * recursive(n-1)` 꼴이 되어야 함
2. base case에 대한 return이 없음. 멈추지 않음
3. 다음과 같이 출력
    ```C++
    5
    4
    3
    2
    1
    0
    //return = 15
    ```
4. 7개
5. 아래 참고
    ```C++
    int ex5(int n){
        if (n == 1) return 1;
        return n + ex5(n-1); 
    }
    ```
6.  아래 참고
    ```C++
    float ex6(float n){
        if (n == 1) return 1;
        return 1/n + ex6(n-1); 
    }
    ```
7. 프로그래밍 프로젝트 1
    ```C++
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

        int n = 3;
        int arr[4] = {0};

        Fibo(n, arr);

        for (int i = n; i >= 0; i--)
            {
                printf("Fibo(%d) = %dtimes\n", i, arr[i]);
            }        
    }
    ```

8. 프로그래밍 프로젝트 2

    ```C++
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

    int main(){
        long result = Fibolong(50);
        std::cout << "Last value : " << result << std::endl;
    }
    ```

9. 프로그래밍 프로젝트 3
    ```C++

    void reverse(const char* word){
        int len = strnlen(word, 100);
        char result[len];

        for (int i = 0; i < len; i++)
        {   
            result[len-1-i] = word[i];
        }

        std::cout << result << std::endl;
    }

    int main(){
        const char* word = "ABCDEFGHIJK";
        reverse(word);
    }
    ```

10. 프로그래밍 프로젝트 4
    ```C++
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
    ```
11. 프로그래밍 프로젝트 5
    ```C++
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

    ```