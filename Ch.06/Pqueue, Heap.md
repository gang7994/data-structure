Priority Queue(우선순위 큐), Heap(힙)
==============================

## Pqueue

- **우선순위를 가진 항목들을 저장하는 큐**

- **FIFO 순서가 아니라 우선 순위가 높은 데이터가 먼저 나감**

|자료구조|삭제되는 요소|
|:-------:|:---------:|
|<span style="color:red">스택</span>|가장 최근에 들어온 데이터|
|<span style="color:blue">큐</span>|가장 먼저 들어온 데이터|
|<span style="color:green">우선순위큐</span>|가장 우선순위가 높은 데이터|

- **응용분야**
    * 시뮬레이션 시스템
    * 네트워크 트래픽 제어
    * 운영체제에서의 작업 스케쥴링

## Pqueue ADT(Abstract Data Type:추상적 자료형)
```
∙객체: n개의 element형의 우선 순위를 가진 요소들의 모임
∙연산: 
▪ create() ::= 우선 순위큐를 생성
▪ init(q) ::= 우선 순위큐 q를 초기화
▪ is_empty(q) ::= 우선 순위큐 q가 비어있는지를 검사
▪ is_full(q) ::= 우선 순위큐 q가 가득 찼는가를 검사
▪ insert(q, x) ::= 우선 순위큐 q에 요소 x를 추가
▪ delete(q) ::= 우선 순위큐로부터 가장 우선순위가 높은 요소를
삭제하고 이 요소를 반환
▪ find(q) ::= 우선 순위가 가장 높은 요소를 반환

```

## 우선 순위 큐 구현 방법
|표현방법|삽입|삭제|
|:----:|:----:|:----:|
|순서없는 배열|O(1)|O(n)|
|순서없는 연결리스트|O(1)|O(n)|
|정렬된 배열|O(n)|O(1)|
|정렬된 연결리스트|O(n)|O(1)|
|힙|O($logn$)|O($logn$)|
>따라서 최악의 경우에도 O(logn)인 힙을 이용하여 구현한다.


## Heap(힙)

- 노드들이 저장하고 있는 키들이 다음과 같은 식을 만족하는 **완전이진트리**
    - 최대 힙(max heap)
        * 부모 노드이 키값이 자식 노드의 키값보다 크거나 같은 완전이진트리
        * Key(부모노드) $>=$ Key(자식노드)
    - 최소 힙(min heap)
        * 부모 노드이 키값이 자식 노드의 키값보다 작거나 같은 완전이진트리
        * Key(부모노드) $<=$ Key(자식노드)

    ![종류](data:image/png;base64,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 "힙")

- 힙의 높이
    > n개의 노드를 가지고 있는 힙의 높이는 $O(logn)$

- 힙의 구현
    - 배열을 이용한 구현
         * 완전이진트리이므로 각 노드에 번호흫 붙임
         * 부모노드와 자식노드를 찾기 쉬움
         > 왼쪽자식의 인덱스 = (부모의 인덱스)*2
         > 오른쪽자식의 인덱스 = (부모의 인덱스)*2+1
         > 부모의 인덱스 = (자식의 인덱스)/2

    ![종류](https://simpledevcode.files.wordpress.com/2015/07/smtku.png "힙 구현")

- 힙에서의 삽입
    - 알고리즘
        1. 힙의 새로운 요소가 들어오면 일단 새로운 노드를 힙의 마지막 노드에 이어서 삽입
        2. 삽입 후에 새로운 노드를 부모 노드들과 교환해서 힙의 성질을 만족
        ```
        insert_max_heap(A, key) 

        heap_size ← heap_size + 1; 
        i ← heap_size; 
        A[i] ← key; 
        while i ≠ 1 and A[i] > A[PARENT(i)] do 
            A[i] ↔ A[PARENT]; 
            i ← PARENT(i);
        ```

- 힙에서의 삭제
    - 알고리즘
        1. 루트노드를 삭제
        2. 마지막 노드를 루트 노드로 이동
        3. 루트에서부터 단말 노드까지의 경로에 있는 노드들을 교환하여 힙성질을 만족
        ```
        delete_max_heap(A)
        
        item ← A[1];
        A[1] ← A[heap_size];
        heap_size←heap_size-1;
        i ← 2;
        while i ≤ heap_size do
            if i < heap_size and A[LEFT(i)] > A[RIGHT(i)]
                then largest ← LEFT(i);
                else largest ← RIGHT(i);
            if A[PARENT(largest)] > A[largest] 
                then break;
            A[PARENT(largest)] ↔ A[largest];
            i ← CHILD(largest);
        return item;
        ```