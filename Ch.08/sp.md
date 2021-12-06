Shortest Path(최단경로)
=====================================

* 단일 출발(single-source) 최단 경로
    단일 노드 v에서 출발하여 그래프 내의 모든 다른 노드에 도착하는 가장 짧은 경로를 찾는 문제

* 단일 쌍(single-pair) 최단 경로
    주어진 노드 u와 u사이의 최단 경로를 찾는 문제

* 전체 쌍(all-pair) 최단 경로
    그래프 내 모든 노드 쌍들 사이의 최단 경로를 찾는 문제

## Dijkstra의 최단 경로 알고리즘
distance[w] = min(distance[w], distance[u]+weight[u][w])
```
// 입력: 가중치 그래프 G, 가중치는 음수가 아님.
// 출력: distance 배열, distance[u]는 v에서 u까지의 최단 거리이다.
shortest_path(G, v)
S←{v}
for 각 정점 w∈G do 
    distance[w]←weight[v][w];
while 모든 정점이 S에 포함되지 않으면 do
    u←집합 S에 속하지 않는 정점 중에서 최소 distance 정점;
    S←S∪{u}
    for u에 인접하고 S에 있는 각 정점 z do
        if distance[u]+weight[u][z] < distance[z]
            then distance[z]←distance[u]+weight[u][z];
```

> Dijkstra의 최단 경로 알고리즘은 주 반복문을 n번 반복하고 내부 반복문을 2n번 반복하므로 **O($n^2$)**의 복잡도를 가짐

</br><br>

## Floyd의 최단 경로 알고리즘
```
floyd(G)
for k ← 0 to n - 1 
    for i ← 0 to n - 1 
        for j ← 0 to n - 1
            A[i][j] = min(A[i][j], A[i][k] + A[k][j])
```

> n개의 정점이 있다면, Floyd의 최단경로 알고리즘은 3중
반복문을 실행되므로 시간 복잡도는 O($n^3$)

## 모든 정점 쌍의 최단경로를 구하는데 있어 두 알고리즘 모두 동일한 O($n^3$)의 복잡도를 가지지만 Floyd의 알고리즘은 매우 간결한 반복구문을 사용하므로 Dijkstra의 알고리즘 보다 효율적일 수 있음