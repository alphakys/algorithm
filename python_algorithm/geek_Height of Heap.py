# User function Template for Python3

class Node:

    def __init__(self, val):
        self.left = None
        self.right = None
        self.data = val


class Tree:

    def __init__(self):
        self.head = None



class Solution:

    def build_tree(self, arr):

        from collections import deque

        t = Tree()
        if not t.head:
            t.head = Node(arr[0])

        value_queue = deque(arr[1:])
        root = t.head
        node_queue = deque()
        node_queue.append(root)

        while value_queue.__len__() > 0:
            root = node_queue.popleft()
            if root:
                if not root.left and value_queue.__len__() > 0:
                    root.left = Node(value_queue.popleft())
                    node_queue.append(root.left)
                if not root.right and value_queue.__len__() > 0:
                    root.right = Node(value_queue.popleft())
                    node_queue.append(root.right)
        return t.head

    def heapHeight(self, N, arr):

        root = self.build_tree(arr)

        root_l = [root]
        height = 0
        leaves_l = []

        while root_l:
            for node in root_l:

                if node.left:
                    leaves_l.append(node.left)
                if node.right:
                    leaves_l.append(node.right)
            height += 1

            root_l = leaves_l
            leaves_l = []

        return height - 1


# code here


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for itr in range(N):
            arr[itr] = int(arr[itr])

        ob = Solution()
        # root = ob.build_tree(arr)
        # print(ob.levelOrder(root))
        print(ob.heapHeight(N, arr))

# } Driver Code Ends
