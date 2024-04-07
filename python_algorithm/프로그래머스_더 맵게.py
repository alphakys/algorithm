import bisect
import heapq

K = 1000

# scoville = [1, 2, 4, 5, 10, 12, 12313]
scoville = [1, 1000]

i = bisect.bisect_left(scoville, K)
arr = scoville[:i]

answer = []
mix_cnt = 0
while len(arr) > 1:

    n1 = heapq.heappop(arr)
    n2 = heapq.heappop(arr)

    mix = n1 + (n2 * 2)
    mix_cnt += 1
    if mix < K:
        arr.append(mix)
    else:
        answer.append(mix)
    # print(n1, n2, mix)
    # print(arr)
    # print()

if answer:
    print(mix_cnt)
else:
    print(-1)