raw_str = input()
N = int(raw_str.split()[0])
K = int(raw_str.split()[1])

# print(f'{int(N)} {int(K)}')
check_list = [1]

for _ in range(2, N + 1):
    if N % _ == 0:
        check_list.append(_)

try:
    print(check_list[K - 1])
except:
    print(0)
