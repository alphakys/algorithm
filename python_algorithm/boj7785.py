
import sys
def main() -> None:
    N = int(sys.stdin.readline())

    log = {}
    for _ in range(N):
        name, operation = sys.stdin.readline().split(' ')
        if log.get(name):
            log.pop(name)
        else:
            log[name] = 1

    keys = sorted(list(log.keys()), reverse=True)
    answer = '\n'.join(keys)

    print(answer)

if __name__ == '__main__':
    main()
