import math

raw_str = input()
N = int(raw_str.split()[0])
K = int(raw_str.split()[1])

sqrt_num = int(math.sqrt(N))

check_list = [1]

for _ in range(2, sqrt_num + 1):
    if N % _ == 0:
        check_list.append(_)
        check_list.append(N // _)
check_list.append(N)
check_list = sorted(set(check_list))

try:
    print(check_list[K-1])
except:
    print(0)
