import sys

n = int(sys.stdin.readline())
if n == 0:
    sys.stdout.write('0')
    exit()
left = 0
right = 1
for _ in range(n - 1):
    tmp = right
    right = left + right
    left = tmp

sys.stdout.write(f'{right}')
