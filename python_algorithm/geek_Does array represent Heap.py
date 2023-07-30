class Node:

    def __init__(self, val):
        self.right = None
        self.left = None
        self.data = val


class Solution:

    def __init__(self):
        self.root = None

    def order_util(self, val):
        root = self.root
        if root.data < val:
            root.data = val
        else:
            if not root.left:
                root.left = Node(val)
            elif not root.right:
                root.right = Node(val)
            else:
                self.order_util(root.left, val)


    def arrayRepresentHeap(self, arr, n):
        # Your code goes here
        if not self.root:
            self.root = Node(arr[0])

        for n in arr[1:]:
            self.order_util(n)


# {
# Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):
        n = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        print(ob.arrayRepresentHeap(arr, n))
# } Driver Code Ends
