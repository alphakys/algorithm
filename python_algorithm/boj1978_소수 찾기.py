import sys

# N = sys.stdin.readline()

# arr = [int(n) for n in sys.stdin.readline().split()]


raw_arr = [n for n in range(2,1001)]

print(raw_arr)

for i in range(2, 4):
    j = 2
    while i * j <= 1000:
        raw_arr.remove(i*j)
        # raw_arr.
        j += 1
print(raw_arr)