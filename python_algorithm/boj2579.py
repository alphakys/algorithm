import copy
import sys

n = int(sys.stdin.readline().rstrip())

stairs = [0] * (n + 1)

for _ in range(1, n + 1):
    stairs[_] = int(sys.stdin.readline().rstrip())

# 초기 조건! 중요

if n == 1:
    print(stairs[n])
    exit()
elif n == 2:
    print(stairs[1] + stairs[2])
    exit()
elif n == 3:
    print(stairs[1] + stairs[3])
    exit()

dp = [[None] * 2 for _ in range(n + 1)]
score_tb = [[0] * 2 for _ in range(n + 1)]

dp[1][0] = [1]  # 10
# score_tb[1][0] = stairs[1]
score_tb[1][0] = stairs[1]

dp[2][0] = [1, 1]  # 30
dp[2][0] = [1, 0]
# score_tb[2][0] = stairs[1] + stairs[2]
score_tb[2][0] = stairs[1] + stairs[2]

dp[3][1] = [1, 2]  # 25
dp[3][0] = [1, 2]
# score_tb[3][1] = stairs[1] + stairs[3]
score_tb[3][1] = stairs[1] + stairs[3]

dp[4][0] = [1, 2, 1]
dp[4][1] = [1, 1, 2]
score_tb[4][0] = stairs[1] + stairs[3] + stairs[4]
score_tb[4][1] = stairs[1] + stairs[2] + stairs[4]

# dp[4] = [1,2,1]/50             || [1,1,2]/55
# dp[5] = [1,2,1,1] ,&&[1,1,2,1]&& <65>  || [1,2,2] <35>
# dp[6] = [1,2,2,1]  || [1,2,1,2] [1,1,2,2]
# dp[7] = [1,1,2,2,1]/55 [1,1,2,1,2]/75 [1,2,1,2,1]/70 [1,2,2,2]/35

print(score_tb)
print(dp)
for idx in range(5, n + 1):

    # 1로 끝나는 dp score
    score = stairs[idx]
    print(idx)
    print(score_tb[idx - 1][0] , score_tb[idx - 1][1])
    print(dp[idx - 1][0][-2:], dp[idx - 1][1][-2:])
    if score_tb[idx - 1][0] > score_tb[idx - 1][1] and dp[idx-1][0][-1:] != [1]:
        score_tb[idx][0] = score + score_tb[idx - 1][0]
        # dp[idx][0] = copy.deepcopy(dp[idx - 1][0][-2:])
        tmp = dp[idx - 1][0][-1:]
        tmp.append(1)
        dp[idx][0] = tmp

    else:
        score_tb[idx][0] = score + score_tb[idx - 1][1]
        dp[idx][0] = dp[idx - 1][1][-2:]
        tmp = dp[idx - 1][1][-1:]
        tmp.append(1)
        dp[idx][0] = tmp


    # 2로 끝나는 dp score
    if score_tb[idx - 2][0] > score_tb[idx - 2][1]:
        score_tb[idx][1] = score_tb[idx - 2][0] + score
        tmp = dp[idx - 2][0][-1:]
        tmp.append(2)
        dp[idx][1] = tmp
    else:
        score_tb[idx][1] = score_tb[idx - 2][1] + score
        tmp = dp[idx - 2][1][-1:]
        tmp.append(2)
        dp[idx][1] = tmp
    # if idx == n:
    #     print(score_tb)
    #     print(max(score_tb[idx]))

print(score_tb)
print(dp)

