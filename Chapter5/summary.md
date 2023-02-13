Chapter 5. 포인터와 연결리스트
===============

* 포인터

```C++
char* p;            // 의미상 더 우수한 방법
char *p;

char *p, *q, *r;    // 다중 선언할 때는 변수 명 앞에 붙여야 함

void (*f)(int);     // int를 매개변수로 갖고 반환이 없는 함수의 주소를 저장하기 위한 포인터
f = func1;          // --> func(10) == f(10) == (*f)(10)

char *pc;           // 초기화 안되어 있어서 위험한 코드
char *pc = NULL;    // 초기화 되어있어 안전
*pc = 'E';          // pc가 초기화 되어있어야 안전

int *pi;
float *pf;
pf = (float*)pi;    // 명시적 형변환 필요

```

* 자체 참조 클래스(self-referential class) : 클래스인데 내부에 동일한 클래스의 객체를 가리키는 포인터가 한 개 이상 존재하는 클래스
    * Linked List나 트리 구성할 때 기본단위로 사용
```C++
typedef struct ListNode ListNode;

struct ListNode{
    char data[10];
    ListNode* link;
};
```
* 동적 메모리 할당
    * 실행 도중 메모리 할당
    * 필요한 만큼만 할당하고 원할 때 해제 가능
    * 행과 열이 정해지지 않은 2차원 배열 만들 수 있음
        * 기본 : Dynamic2D.cpp 참고
        * new 한번 사용 : Dynamic2D_2.cpp 참고
```C++
// int 동적할당
int x;              // 정적할당
int* py = new int;  // 동적할당
x = 10;             
*py = 20;
delete py;          // 동적할당 해제

// 배열 동적할당
int arrA[20];
int* arrB = new int [20];
arrA[3] = 10;
arrB[3] = 20;
delete [] arrB;
```

* Linked List
    * node로 구성 : data field + link field(default 값은 NULL)
    * head pointer : 시작점을 pointing  
    * 종류
        * Single linked list : 한 방향으로 연결
        * Circular linked list : 마지막 노드가 첫번째 노드 pointing
        * Doubly linked list : 앞 뒤로 연결(link field 2개 필요)


        