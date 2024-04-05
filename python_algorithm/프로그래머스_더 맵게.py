import bisect

K = 7

scovile = [1, 2, 12313, 4, 5, 10, 12]

i = bisect.bisect_left(scovile, K)

arr = scovile[:i]

# print(arr, len(arr))
stop = len(arr)

lp = 0
rp = 1
cnt = 0
while rp < stop:
    print("check : ", lp, rp, stop)
    print(arr)
    mix = arr[lp] + (arr[rp]*2)
    cnt += 1
    if mix < K:

        # print(mix)
        # print(bisect.bisect_left(arr, mix))
        bisect.insort(arr, mix)
        stop += 1
    else:
        pass
    lp += 2
    rp += 2

    # break

print(cnt)

