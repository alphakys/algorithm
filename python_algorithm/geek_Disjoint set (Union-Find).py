# function should return parent of x
def find(A, X):
    # Code here
    parent_node = X
    while True:
        if A[parent_node - 1] == parent_node:
            break

        parent_node = A[parent_node - 1]

    # print("X : ", X, "parent_node : ", parent_node)
    return parent_node

# Z의 부모는 X의 부모가 될 것이다.
# 5의 부모는 3의 부모가 될 것이다.

# 5의 부모는 31의 부모가 될 것이다.

# function shouldn't return or print anything
def unionSet(A, X, Z):
    # Code here
    # 3의 부모 -> 1
    parent_X = find(A, X)
    # 5의 부모 -> 5
    parent_Z = find(A, Z)

    #   1            5
    if parent_X != parent_Z:
        # 5    1
        A[Z - 1] = parent_X

        # print(f"Union ! {X}, {Z}")
        # print(A)
    return A
# UNION 1 3 UNION 3 5 UNION 31 5
#
# 1
# 3 31
#     5


#
# 1
# 3
# 5

# 46 13 23 51 45 39 22 22 42 54 39 54 25 23 45 16 40 42 15 13 15
# {
# Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        n, k = list(map(int, input().strip().split()))
        arr = [x for x in range(1, n + 1)]
        s = input().strip().split()
        i = 0
        while i < len(s):
            if s[i] == 'FIND':
                print(find(arr, int(s[i + 1])), end=" ")
                i += 2
            elif s[i] == 'UNION':
                unionSet(arr, int(s[i + 1]), int(s[i + 2]))
                i += 3
        print()
# Contributed by: Harshit Sidhwa

# } Driver Code Ends