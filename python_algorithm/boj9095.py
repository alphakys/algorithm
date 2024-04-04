import sys
from io import StringIO

t = int(sys.stdin.readline())

test_cases = [0] * t
max_val = 0
for _ in range(t):
    n = int(sys.stdin.readline())
    if n > max_val:
        max_val = n
    test_cases[_] = n

if max_val == 1:
    print(1)
    exit()
elif max_val == 2:
    print(2)
    exit()
elif max_val == 3:
    print(4)
    exit()

dp = [0] * (max_val + 1)

dp[1] = 1
dp[2] = 2
dp[3] = 4

dp_start_num = 4

while dp_start_num <= max_val:
    dp[dp_start_num] = dp[dp_start_num - 1] + dp[dp_start_num - 2] + dp[dp_start_num - 3]

    dp_start_num += 1

out = StringIO()
for i in test_cases:
    out.write(f'{dp[i]}\n')

print(out.getvalue())
