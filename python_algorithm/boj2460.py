import sys

get_off, get_on = sys.stdin.readline().split()
curr = int(get_on)
max_passenger = curr

for _ in range(9):

    get_off, get_on = sys.stdin.readline().split()

    newcomer = int(get_on) - int(get_off)
    curr = curr + newcomer
    # print(f'curr : {curr}, newcomer : {newcomer}')

    if curr > max_passenger:
        max_passenger = curr

sys.stdout.write(f'{max_passenger}')
