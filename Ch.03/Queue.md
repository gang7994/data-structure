Queue
========================

## 큐의 특징

- **선입선출**: FIFO(First-in first-out)
    먼저 들어온 데이터가 먼저 나감

- **Queue ADT(Abstract Data Type:추상적 자료형)**
    ```
    create() : 큐를 생성
    init(q) : 큐를 초기화
    is_empty(q) : 큐가 비어있는지 검사
    is_full(q) : 큐가 가득찼는가를 검사
    enqueue(q,e) :  큐의 뒤에 요소e를 추가
    dequeue(q) : 큐의 앞에 있는 요소를 반환하고 삭제
    peek(q) : 큐에서 삭제하지 않고 요소를 반환
    ```
</br></br> 

## 큐의 응용

- **배열을 이용한 큐**
   
    - **선형큐** : 배열을 선형으로 사용하여 큐 구현
    > 삽입을 계속하기 위해 요소들을 이동시켜야 함, 잘사용X
    ![예시](https://t1.daumcdn.net/cfile/tistory/2709AA3C537BF4CA27 "선형큐")

    - **원형큐** : 배열을 원형으로 사용하여 큐 구현
    >![예시](https://blog.kakaocdn.net/dn/mAiv4/btqyfXRxQsU/aS7QZ9Xki49reyhmVKkf2k/img.png "원형큐")
        
        - 큐의 전단과 후단을 관리하기 위해 2개의 변수 필요
            - front : 첫번째 요소 하나 앞의 인덱스 // 삭제와 관련
            - rear : 마지막 요소의 인덱스 // 삽입과 관련



