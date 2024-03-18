import sys

N, K = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

coins = [0] * N
for _ in range(N):
    coins[_] = int(sys.stdin.readline().rstrip())

# K = 4790
# coins = [1,5,10,50,100,500,1000,5000,10000,50000]

cnt = 0
while K > 0:

    for i in range(len(coins) - 1, -1, -1):
        if coins[i] > K:
            continue

        if K % coins[i] == 0:
            cnt += K // coins[i]
            K = 0
            break
        else:
            cnt += K // coins[i]
            K = K % coins[i]

print(cnt)
