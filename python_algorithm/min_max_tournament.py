import sys

n = int(sys.stdin.readline())
arr = [int(n) for n in sys.stdin.readline().split()]

if n <= 5:
    sys.stdout.write(f'{min(arr)} {max(arr)}')
else:

    start_pos = 0
    end_pos = n - 1
    length = n

    while length > 2:
        tournament = []

        while start_pos < length // 2:

            if arr[start_pos] >= arr[start_pos + 1]:
                left_max = arr[start_pos]
                left_min = arr[start_pos + 1]
            else:
                left_max = arr[start_pos + 1]
                left_min = arr[start_pos]

            if arr[end_pos] >= arr[end_pos - 1]:
                right_max = arr[end_pos]
                right_min = arr[end_pos - 1]
            else:
                right_max = arr[end_pos - 1]
                right_min = arr[end_pos]

            tournament.append(left_max) if left_max >= right_max else tournament.append(right_max)
            tournament.append(right_min) if left_min >= right_min else tournament.append(left_min)

            start_pos += 2
            end_pos -= 2

        length = tournament.__len__()
        arr = tournament
        start_pos = 0
        end_pos = length - 1

    sys.stdout.write(f'{tournament[1]} {tournament[0]}')
