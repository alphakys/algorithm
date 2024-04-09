import bisect
import heapq

K = 5

scoville = [1, 2, 3, 9, 10, 12]
scoville = [1, 2, 3]
# scoville = [1,1,1,1,1,1,100,100,100,100,0,0,0,0,0]

# i = bisect.bisect_left(scoville, K)
# scoville = scoville[:i]

heapq.heapify(scoville)

answer = 0
arr = []
while len(scoville) > 1:

    n1 = heapq.heappop(scoville)
    n2 = heapq.heappop(scoville)

    if n1 >= K and n2 >= K:
        arr.append(n1)
        break

    mix = n1 + (n2 * 2)
    answer += 1
    if mix < K:
        print("mix : ", mix)
        heapq.heappush(scoville, mix)
        print(scoville)
    else:
        arr.append(mix)
        heapq.heappush(scoville, mix)

print(arr)
if len(arr) == 0:
    answer = -1

print(answer)
# 11