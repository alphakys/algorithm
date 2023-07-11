import sys
import math

N, K = sys.stdin.readline().split()
N = int(N)
K = int(K)
n = int(math.sqrt(N))

divisor_list = []
for _ in range(1, n + 1):
    if N % _ == 0:
        divisor_list.append(_)
        divisor_list.append(N // _)

try:
    sys.stdout.write(f'{sorted(set(divisor_list))[K - 1]}')
except Exception:
    sys.stdout.write('0')