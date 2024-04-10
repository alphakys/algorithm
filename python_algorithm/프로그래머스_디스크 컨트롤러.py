import heapq as hq


def solution(jobs):
    answer = 0

    start_seconds = [j[0] for j in jobs]
    end_seconds = [j[1] for j in jobs]
    scheduler = []

    hq.heappush(scheduler, end_seconds[0])

    [0, 1, 2]
    [3, 9, 6]

    # while True:
    t = hq.heappop(scheduler)

    for i, s in enumerate(start_seconds[1:]):
        if s <= t:
            elasped = t + end_seconds[i+1] - start_seconds[i+1]
            hq.heappush(scheduler, elasped)
            print(t, end_seconds[i], start_seconds[i], elasped)

    print(scheduler)

    # print(start_seconds)
    # print(end_seconds)
    return answer


def main() -> None:
    jobs = [[0, 3], [1, 9], [2, 6]]

    # 0-index를 시작점으로 잡고 작업 종료 시점에서 값을 빼는 것을 구하기
    solution(jobs)

    # B가 종료까지 걸린 시간
    # 3 - 1 + 9
    #     # C가 시작
    #     시작점 : (3 + 9) + 6 - 2
    #
    # 3 - 2


if __name__ == '__main__':
    main()
