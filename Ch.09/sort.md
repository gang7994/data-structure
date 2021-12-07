Sorting(정렬)
===================================

## Sorting

- 단순하지만 비효율적인 방법
    * 선택 정렬
    * 삽입 정렬
    * 버블 정렬

- 복잡하지만 효율적인 방법
    * 퀵 정렬
    * 힙(heap) 정렬
    * 합병 정렬
    * 기수 정렬

- **internal sorting**(내부 정렬) : 모든 데이터가 주기억장치에 저장된 상태에서 정렬
- **external sorting**(외부 정렬) : 외부 기억장치에 대부분의 데이터가 잇고 일부만 주기억장치에 저장된 상태에서 정렬

- **정렬 알고리즘의 안정성(stability)** 
    > 입력 데이터에 동일한 값을 갖는 레코드가 존재하는 경우 동일한 값을 갖는 레코드들의 상대적인 위치가 정렬 후에도 변하지 않음
------------------------------------
</br></br>

## 선택 정렬(Selection Sort)

- 입력 배열 이외에 추가적인 공간을 사용하지 않음
- 입력 배열에서 최소값을 발견하고 이 최소값을 배열의 첫 번째 요소와 교환
- 첫 번째 요소를 제외한 나머지 요소들 중에서 가장 작은 값을 선택하고 이를 두번째 요소와 교환(이러한 과정 반복)

![예시](https://gmlwjd9405.github.io/images/algorithm-selection-sort/selection-sort.png "선택정렬")

```
selection_sort(A,n)

for i<-0 to n-1 do
    least <- A[i],A[i+1],...,A[n-1] 중에서 가장 작은 값의 인덱스;
    A[i] 와 A[least] SWAP;
    i++;
```

- **시간 복잡도 : O($n^2$)** : 2개의 for문
> 안정성을 만족하지 않음(값이 같은 데이터가 있는 경우 상대적인 위치 변경 가능)
--------------------------------------
</br></br>

## 삽입 정렬(Insertion Sort)

- 정렬되어 있는 리스트에 새로운 레코드를 올바른 위치에 삽입하는 과정 반복
- 안정된 정렬 방법
- 대부분 정렬되어 있으면 매우 효율적

```
insertion_sort(A, n)
1. for i ← 1 to n-1 do
2.  key ← A[i];
3.  j ← i-1;
4.  while j≥0 and A[ j]>key do
5.      A[ j+1] ← A[ j];
6.      j ← j-1;
7.  A[ j+1] ← key
```
>1. 인덱스 1부터 시작
>2. 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
>3. 현재 정렬된 배열은 i-1까지 이므로, i-1번째부터 역순으로 조사
>4. j값이 음수가 아니어야 되고 key값보다 정렬된 배열에 있는 값이 크면 수행
>5. j번째를 j+1번째로 이동
>6. j를 하나 감소
>7. j번째 정수가 key보다 작으므로 j+1번째가 key값이 들어갈 위치

![예시](https://www.w3resource.com/w3r_images/insertion-sort.png "삽입정렬")

- **시간 복잡도 분석**
    - 최선의 경우 : O($n$) 이미 정렬된 경우 
    - 최악의 경우 : O($n^2$) 역순으로 정렬되어 있는 경우 
    - 평균의 경우 : O($n^2$) 
-------------------------------------
</br></br>

## 버블 정렬(Bubble Sort)

- 인접한 2개의 레코드를 비교하여 순서대로 되어 있지 않으면 서로 교환
- 이러한 비교-교환 과정을 리스트의 왼쪽 끝에서 오른쪽까지 반복

![예시](https://gmlwjd9405.github.io/images/algorithm-bubble-sort/bubble-sort.png "버블정렬")

```
BubbleSort(A, n)
for i←n-1 to 1 do 
    for j←0 to i-1 do //하나의 스캔 과정
    j와 j+1번째의 요소가 크기 순이 아니면 교환
    j++;
i--;
```

- **시간복잡도 분석**
    * 최상, 최악, 평균 : O($n^2$)

- 레코드의 이동 과다 : 이동 연산은 비교 연산보다 더 많은 시간이 소요됨 

---------------------------
</br></br>

## 합병 정렬(Merge Sort)

- 분할 정복(divide and conquer) 방법 사용
    * 문제를 보다 작은 2개의 문제로 분리하고 각 문제를 해결한후 결괄를 모아서 원래의 문제를 해결하는 전략
    * 분리된 문제가 아직도 해결하기 어렵다면 분활정복 방법을 다시 적용
    ```
    입력 : (27 10 12 20 25 13 15 22)
    1. 분할(Divide) : 배열을 같은 크기의 2개의 부분 배열로 분할 (전체 배열을 (27 10 12 20), (25 13 15 22) 2개 부분배열로 분리)

    2. 정복(Conquer) : 부분배열을 정렬한다.  (각 부분배열 정렬 (10 12 20 27), (13 15 22 25))

    3. 결합(Combine) : 정렬된 부분배열을 하나의 배열에 통합 (2개의 정렬된 부분배열 통합 (10 12 13 15 20 22 25 27))
    ```
    ![예시](https://t1.daumcdn.net/cfile/tistory/214EFE385452034624 "합병정렬")

- **합병정렬 알고리즘**
    ```
    merge_sort(list, left, right)

    if left < right   //나누어진 구간의 크기가 1이상이면
        mid = (left+right)/2; //중간위치 계산
        merge_sort(list, left, mid); //왼쪽부분 배열 정렬
        merge_sort(list, mid+1, right); //오른쪽부분 배열 정렬
        merge(list, left, mid, right); //부분배열을 통합
    ```
    ```
    merge(list, left, mid, right)
    // 2개의 인접한 배열 list[left..mid]와 list[mid+1..right]를 합병
    i←left;
    j←mid+1;
    k←left;
    sorted 배열 생성; //합병된 리스트를 임시로 저장하기 위한 배열
    while i≤left and j≤right do
        if(list[i]<list[j]) 
            then
                sorted[k]←list[i];
                k++;
                i++;
            else
                sorted[k]←list[ j];
                k++;
                j++;
    요소가 남아있는 부분배열을 sorted로 복사한다;
    sorted를 list로 복사한다;
    ```

- **시간복잡도 분석**
    > 순환 호출의 깊이(합병 단계의 수) : 레코드의 개수 n이 2의 거듭제곱일때, $log_2n$
    - 비교 연산 : 각 합병 단계의 비교연산 * 순환 호출의 깊이 만큼의 합병 단계 (n $log_2n$)

    - 이동 연산 : 각 합병 단계의 이동 연산 * 순환 호출의 깊이 만큼의 합병 단계 (2n $log_2n$)
    
    > T(n) = n $log_2n$(비교) + 2n $log_2n$(이동) = 3n $log_2n$ = O(n $log_2n$)

---------------------------

## 퀵 정렬(Quick Sort)

- 평균적으로 가장 빠른 정렬
- 분할 정복법(Davide & Conquer) 사용
- 리스트를 2개의 부분리스트로 분할하고, 각각의 부분리스트를 다시 퀵 정렬함

    ![예시](https://lh3.googleusercontent.com/proxy/yagUpWPJ3yo950K39gF6fU786ox-xNbvSU29YeHM08TdpIV6rIZjLE68DGqtWbPAOd1a1ybO_r2A-S-TLyEnpIP9Pf_w31HOExbPvfoTsnSaUEXigOJwhoMQ "퀵정렬")

```
void quick_sort(int list[], int left, int right)
{ 
1. if(left<right){ 
2.     int q=partition(list, left, right); //가장 중요한 함수
3.     quick_sort(list, left, q-1); 
4.     quick_sort(list, q+1, right); 
    }
}
1. 정렬할 범위가 2개 이상의 데이터이면
2. partition 함수 호출로 피벗을 기준으로 2개의 리스트로 분할 partition 함수의 반환 값이 피벗의 위치
3. left에서 피벗 바로 앞까지를 대상으로 순환호출(피벗 제외)
4. 피벗 바로 다음부터 right까지를 대상으로 순환호출(피벗 제외)
```

- **퀵 정렬의 시간복잡도 분석**
    - 최선의 경우 ($n logn$)
        * 분할 횟수 : $logn$
        * 비교횟수 : $n$
        * 총 비교 횟수 $n logn$
    - 최악의 경우 ($n^2$)
        * 분할 횟수 : $n$
        * 비교횟수 : $n$
        * 총 비교 횟수 $n^2$