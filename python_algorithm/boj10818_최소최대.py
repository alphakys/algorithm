
N = int(input())

import sys
s = sys.stdin.readline()

num_arr = sorted([int(num) for num in s.split()])

sys.stdout.write(str(num_arr[0])+ ' ' + str(num_arr[-1]))
