Chapter 6. 리스트
===============
----
* 리스트
    * top, front, rear같이 접근방법에 제한 없음-> 임의의 위치 접근 가능
    * **리스트 : 자료구조, ==연결리스트 : 자료구조를 구현하는 프로그래밍 기법==**
    * 기본연산
        1. insert(pos, item)
        2. delete(pos)
        3. getEntry(pos) : pos 위치에 있는 요소 반환
        4. isEmpty()
        5. isFull()
        6. find(item)
        7. replace(pos, item)
        8. size()
        9. display()


    * 구현
        * 배열 : `ArrayList.cpp`, *편하지만 크기에 제약*
            * 삽입, 삭제 시 많은 데이터의 복붙이 추가로 필요
            * insert는 마지막에 새롭게 삽입이 가능하지만 remove는 있는 걸 삭제해야해서 조건문에 `pos<length` 가 되어야 함
            * 같은 이유로 remove는 for loop 조건도 신경써야 함
            ```C++
            for(int i = pos + 1 ; i < length ; i++){
                data[i-1] = data[i]
            }

            for(int i = pos ; i < length - 1 ; i++){
                data[i] = data[i+1]
            }
            ```

        * 연결리스트 : `LinkedList.cpp`
            * 배열로 구현했을 때의 크기 제약, 데이터 복사 문제 해결
            * 여기서는 head pointer가 아닌 head node를 갖도록 구현 -> sentinel의미, 삽입/삭제에서 편해짐
            * Node class와 LinkedList class가 필요
                * Node class에서 주요 기능을 다 구현하는 것이 객체지향(bottom up) 측면에서 바람직
            * `Node* getEntry(int pos)`의 구현에 유의. insert, remove에서 활용
---

* 다양한 형태의 연결리스트
1. 원형 연결 리스트(circular linked list)
    * 한 노드에서 모든 노드로 접근 가능
    * 맨 뒤에 삽입하는 연산이 `O(1)`
2. 이중 연결 리스트(doubly linked list)
    * 선행 노드도 찾을 수 있음. 노드에 포인터가 2개: `prev`, `next` 
    * 양방향 검색되지만 코드 복잡 + 공간 많음
