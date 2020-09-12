from sys import stdin, stdout, maxsize
from heapq import heappop, heappush

def dijkstra(arr, K):
    dis = [maxsize]*len(arr)
    dis[K] = 0
    pq = []
    heappush(pq, [0, K])
    while pq:
        current_p, current = heappop(pq)
        for _, leng in arr[current].items():
            next_dis = dis[current] + leng
            if next_dis < dis[_]:
                dis[_] = next_dis
                heappush(pq, [next_dis, _])
    return dis

if __name__ == '__main__':
    V, E = list(map(int, stdin.readline().split()))
    arr = [{} for i in range(V + 1)]
    K = int(input())
    for _ in range(E):
        u, v, w = list(map(int, stdin.readline().split()))
        if v in arr[u]:
            arr[u][v] = min(arr[u][v], w)
        else:
            arr[u][v] = w
    dis = dijkstra(arr, K)
    
    for _ in dis[1:]:
        stdout.write(str(_)+'\n' if _ != maxsize else "INF\n" )