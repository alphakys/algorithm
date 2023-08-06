# User function Template for python3

class Solution:
    def isTree(self, n, adj):
        ans = 0
        print(n, adj)
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

for _ in range(int(input())):
    n, m = [int(i) for i in input().split()]
    adj = [[] for i in range(n)]
    for i in range(m):
        u, v = [int(i) for i in input().split()]
        adj[u].append(v)
        adj[v].append(u)

    ob = Solution()
    print(ob.isTree(n, adj))
# } Driver Code Ends