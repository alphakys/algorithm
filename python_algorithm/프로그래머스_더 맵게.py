import bisect
import heapq as hq


# scoville = [1,1,1,1,1,1,100,100,100,100,0,0,0,0,0]


def solution(scoville, K):
    answer = 0
    hq.heapify(scoville)

    while len(scoville) > 1:
        if scoville[0] >= K:
            break

        answer += 1
        first = hq.heappop(scoville)
        secondary = hq.heappop(scoville)

        mix = first + secondary*2
        # print(mix)
        hq.heappush(scoville, mix)

    # print(scoville, answer)
    if scoville[0] < K:
        answer = -1
    # print(answer)
    return answer


def main() -> None:
    K = 7

    scoville = [1, 2, 3, 9, 10, 12]
    # scoville = [11, 1, 2, 3]
    # scoville = [1, 2]

    solution(scoville, K)


if __name__ == '__main__':
    main()
