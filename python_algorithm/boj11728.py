import io
import sys

N, M = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

A = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))
B = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

length = (N + M)
sorted_arr = [0] * length

aidx = 0
bidx = 0

sidx = 0
while sidx < length:

    if aidx == N:
        sorted_arr[sidx] = B[bidx]
        bidx += 1

    elif bidx == M:
        sorted_arr[sidx] = A[aidx]
        aidx += 1

    elif A[aidx] >= B[bidx]:
        sorted_arr[sidx] = B[bidx]
        bidx += 1

    else:
        sorted_arr[sidx] = A[aidx]
        aidx += 1

    sidx += 1

output = io.StringIO()
for n in sorted_arr:
    output.write(f"{n}\n")

sys.stdout.write(output.getvalue())
