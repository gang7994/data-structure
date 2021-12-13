Hashing(해싱)
==============================

- 키 값에 대한 산술적 연산에 의해 테이블의 주소를 계산하여 항목에 접근

## hash table 구성

- **key**
    * 고유한 값, 해시테이블의 input이 된다.
    * key값을 그대로 저장소의 색인으로 사용할 경우 key길이 만큼의 정보를 저장해야하는 공간도 마련해야 하기 때문에 고정된 길이의 해시로 변경한다.

- **hash function**
    * key를 고정된 길이의 hash로 변경해주는 역할을 한다.

- **value**
    * 저장소에 최종적으로 저장되는 값으로, hash와 매칭되어 저장되어진다.

- **hash table**
    * 해시 함수를 사용하여 키를 해시 값으로 매핑하고, 이 해시값을 주소또는 색인 삼아 데이터(value)를 key와 함꼐 저장하는 자료구조임
    * 데이터가 저장되는 곳을 버킷,슬롯이라고 함.

![예시](https://dl1gtqdymozzn.cloudfront.net/forAuthors/VPXjzivoBmRcG3Bt3vnMRvYwQ46D38x6ROCiEZV3.webp "해시구조")

</br></br>

## Hash function

- **좋은 해시 함수의 조건**
    * 충돌이 적어야 함
    * 해시함수 값이 해시테이블의 주소 영역내에서 고르게 분포되어야 함
    * 계산이 빨라야 함

- **제산함수*(Division Function)**
    * $h(k)$ = $k$ mod $M$
    * M으로 나눈 나머지 값의 범위는 0 ~ (M-1)이 되므로 해시 테이블의 인덱스로 사용할수 있음
    * 키값을 나눈느 테이블의 크기 M은 적당한 크기의 소수를 사용

- **폴딩함수(Folding Function)**
    * 이동폴딩(shift folding)
    ![예시](https://t1.daumcdn.net/cfile/tistory/993DFB3B5A77B59403 "이동폴딩")
    * 경계폴딩(boundary folding)
    ![예시](https://t1.daumcdn.net/cfile/tistory/9906E73D5A77B5BB31 "경계폴딩")

- **중간제곱함수(Mid-Square Function)**
    * 탐색키를 제곱한 다음, 중간의 몇 비트를 취해서 해시 주소 생성
    ![예시](https://t1.daumcdn.net/cfile/tistory/99A2C3385A77B55128 "중간제곱함수")


