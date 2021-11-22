Binary Search Tree(이진탐색트리)
=================================

## 이진탐색트리 정의

- **이진탐색트리** : 공집합이거나 다음을 만족하는 이진 트리
> - 공집합이 아닌 왼쪽 부분 트리의 모든 키캆은 루트의 키값보다 작음
> - 공집합이 아닌 오른쪽 부분 트리의 모든 키값은 루트의 키값보다 큼
</br></br>

## 이진탐색트리 탐색 연산

- **아이디어**
    * 탐색하고자 하는 키값이 루트 노드보다 작으면 왼쪽 노드로 크면 오른쪽 노드로 탐색을 함

- **알고리즘**
    - 루트가 NULL이면 탐색 실패
    - 루트의 원소값 = key 이면 탐색 성공 및 종료
    - 루트의 원소값 > key 이면 왼쪽 부분 츠리를 재귀적으로 탐색
    - 루트의 원소값 < key 이면 오른쪽 부분 트리를 재귀적으로 탐색
    - **시간복잡도 : O(h),트리의 높이 h**
```
search(x, k)
if x==NULL
then return NULL;
if k==x->key
then return x;
else if k < x->key
then return search(x->left, k);
else return search(x->right, k);
```
</br></br>

- **구현**
>순환적인 탐색 함수
```
TreeNode *search(TreeNode *node, int key) {
    if ( node == NULL ) 
        return NULL;
    if ( key == node->key ) 
        return node; 
    else if ( key < node->key )
        return search(node->left, key); 
    else
        return search(node->right, key); 
}
```

>반복적인 탐색 함수
```
TreeNode *search(TreeNode *node, int key) { 
    while(node != NULL) { 
        if( key == node->key ) 
            return node; 
        else if( key < node->key ) 
            node = node->left; 
        else
            node = node->right; 
    } 
    return NULL; // 탐색에 실패했을 경우 NULL 반환
} 
```
</br></br>

## 이진탐색트리 삽입 연산

- **아이디어**
    - key를 탐색, 탐색이 실패한 위치에 새로운 노드 삽입

- **알고리즘**
    - case 1 : 비어있는 트리에 노드를 삽입
    - case 2 : 삽입하고자 하는 key가 트리에 이미 존재 
    - case 3 
        * 새로운 노드를 기존 노드의 왼쪽 자식 링크에 삽입하는 경우
        * 새로운 노드를 기존 노드의 오른쪽 자식 링크에 삽입하는 경우
```
insert_node(T, key)
p←NULL; //p: 부모노드 포인터
T←T; //t: 탐색을 위한 포인터
While t≠NULL do //탐색을 수행함
    p←t; //현재 탐색 포인터 값을 부모 노드 포인터에 복사
if key < p->key
    then t←p->left;
    else t←p->right;
z ← make_node(key);
// 삽입
if p=NULL
    then T←z; // 트리가 비어있음
else if key < p->key
    then p->left←z
    else p->right←z
```
</br></br>

- **구현**
```
// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.
void insert_node(TreeNode **root, int key) {
    TreeNode *p, *t; // p는 부모노드, t는 현재노드
    TreeNode *n; // n은 새로운 노드
    t = *root;
    p = NULL;
    // 탐색을 먼저 수행
    while (t != NULL){
        if( key == t->key ) return;
        p = t;
        if( key < t->key ) t = p->left;
        else t = p->right;
    }
    // key가 트리 안에 없으므로 삽입 가능
    // 트리노드 구성
    n = (TreeNode *) malloc(sizeof(TreeNode));
    if( n == NULL ) return;
    // 데이터 복사
    n->key = key;
    n->left = n->right = NULL;
    // 부모 노드와 링크 연결
    if( p != NULL ) 
        if( key < p->key ) 
            p->left = n;
        else p->right = n;
    else *root = n;
}
```