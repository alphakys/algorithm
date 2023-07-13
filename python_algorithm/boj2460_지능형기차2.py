import sys

total = [int(n) for n in sys.stdin.readline().split()][1]
max_ = total
for _ in range(9):
    get_off, get_on = [int(n) for n in sys.stdin.readline().split()]
    curr = get_on - get_off + total

    if max_ < curr:
        max_ = curr
    total = curr

print(max_)