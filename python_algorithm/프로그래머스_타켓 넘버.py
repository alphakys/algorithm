
from itertools import product

l = [0, 1]

for _ in range(5):


exit()
from itertools import product

product = product([0, 1], repeat=len(l))

target = 3
answer = 0
for pro in product:

    result = [l[idx] if _ == 0 else l[idx]*-1 for idx, _ in enumerate(pro)]
    if sum(result) == target:
        answer += 1

print(answer)
