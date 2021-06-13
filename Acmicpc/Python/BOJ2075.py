import sys
import heapq
heap = []
# sys.stdin = open("input.txt", "r")
n = int(input())
if n == 1:
    print(int(input()))
    exit(0)
lower = 1e8+1
for _ in range(n):
    m = map(int, sys.stdin.readline().split())
    for num in m:
        if len(heap) == n and lower < num:
            lower = heapq.heappop(heap)
            heapq.heappush(heap, num)
        if len(heap) < n:
            lower = num if lower > num else lower
            heapq.heappush(heap, num)
print(heapq.heappop(heap))
