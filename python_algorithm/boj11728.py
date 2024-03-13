import sys

N, M = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

A = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))
B = list(map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')))

sorted_arr = [0] * (N + M)

aidx = 0
bidx = 0

pivot = 0
while pivot < (N + M):

    if aidx == N:
        sorted_arr[pivot] = str(B[bidx])
        bidx += 1
    elif bidx == M:
        sorted_arr[pivot] = str(A[aidx])
        aidx += 1
    elif A[aidx] > B[bidx]:
        sorted_arr[pivot] = str(B[bidx])
        bidx += 1
    else:
        sorted_arr[pivot] = str(A[aidx])
        aidx += 1
    pivot += 1

sys.stdout.write(" ".join(sorted_arr))
