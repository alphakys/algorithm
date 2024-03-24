import sys


def union(sa, sb, rep_l, rank):
    if sa == sb:
        return

    ## 핵심 개념은 tree의 height(rank)가 짧을수록 검색 속도는(find) 빨라진다.
    # 따라서 rank가 짧은 node에 연장하도록 한다.
    rep_a = find(sa, rep_l)
    rep_b = find(sb, rep_l)
    if rep_a == rep_b:
        return

    if rank[rep_a] > rank[rep_b]:
        rep_l[rep_b] = rep_a

    elif rank[rep_a] == rank[rep_b]:
        rep_l[rep_b] = rep_a
        rank[rep_a] += 1
    else:
        rep_l[rep_a] = rep_b

    # print(rep_l)
    # print(rank)


def find(node, par_tree):
    par_node = node
    rank = 0
    while True:
        if par_tree[par_node] == par_node:
            break

        par_node = par_tree[par_node]
        rank += 1

    return par_node


def main() -> None:
    N, M = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

    rep_l = [n for n in range(N + 1)]
    rank = [0] * (N + 1)

    for _ in range(M):
        op, a, b = map(lambda x: int(x), sys.stdin.readline().rstrip().split(' '))

        if op == 0:
            union(a, b, rep_l, rank)
        else:
            if op == 1:
                pa = find(a, rep_l)
                pb = find(b, rep_l)

                if pa == pb:
                    print("YES")
                else:
                    print("NO")

    # print(rep_l)
    # print(rank)


if __name__ == '__main__':
    main()
