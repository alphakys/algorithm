
class Node:

    def __init__(self, val):
        self.left = None
        self.right = None
        self.val = val


def main() -> None:
    import sys
    from collections import deque

    # N, M, V = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))
    N = sys.stdin.readline().rstrip()
    a, b, c = sys.stdin.readline().rstrip().split(' ')
    root = Node(a)
    root.left = Node(b if b != '.' else None)
    root.right = Node(c if c != '.' else None)

    parent = root
    for _ in range(N-1):
        a, b, c = sys.stdin.readline().rstrip().split(' ')


if __name__ == '__main__':
    main()