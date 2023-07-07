import math

raw_str = input()
N = int(raw_str.split()[0])
K = int(raw_str.split()[1])

# 약수 d1 d2 중에서 d1, d2가 가장 크게 나오는 수는 제곱근

sq_num = int(math.sqrt(N))
answer = []
for _ in range(1, sq_num+1):
    if N % _ == 0:
        answer.append(_)
        answer.append(int(N/_))

answer = sorted(set(answer))
try:
    print(answer[K-1])
except:
    print(0)

