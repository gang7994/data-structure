Stack
====================

## 스택의 특징

- **후입선출**: LIFO(Last-in first-out)
    가장 최근에 들어온 데이터가 가장 먼저 나감

- **스택 ADT(Abstract Data Type:추상적 자료형)**
    ```
    create() : 스택을 생성
    is_empty(s) : 스택이 비어있는지 검사
    is_full(s) : 스택이 가득찼는가를 검사
    push(s,e) : 스택의 맨위에 요소 e를 추가
    pop(s) : 스택의 맨 위에 있는 요소를 삭제하고 반환
    peek(s) : 스택의 맨 위에 있는 요소를 삭제하지 않고 반환
    ```
</br></br>

## 스택의 용도

- **자료의 출력 순서가 입력 순서의 역순으로 이뤄저야 할떄**

- **에이터에서 되돌리기 기능**

- **함수 호출에서 복귀 주소 기억**
</br></br>

## 배열을 이용한 스택의 구현

- is_empty
```
is_empty(s)
if top = -1
    then return TRUE
    else return FALSE
```
- is_full
```
is_full(s)
if top = (MAX_STACK_SIZE-1)
    then return TRUE
    else return FALSE
```
- push(s,x)
```
if is_full(s)
    then error "overflow"
    else top <- top+1
         stack[top] <-x
```
- pop(s)
```
if is_empty(s)
    then error "underflow"
    else e <- stack[top]
         top <- top-1
         return e
```