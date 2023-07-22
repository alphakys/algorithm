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

    def build_tree(self):
        pass

    def heapHeight(self, N, arr):

        t = Tree()
        if not t.head:
            t.head = Node(arr[0])

        from queue import Queue
        from collections import deque

        q = Queue()
        value_queue = deque(arr)

        root = t.head
        q.put(value_queue.popleft())

        while value_queue.__len__() > 0:



        while not q.empty():

            # for val in value_queue:
            if not root.left:
                root.left = Node(value_queue.popleft())
                continue
            if not root.right:
                root.right = Node(value_queue.popleft())
                continue

        print()
        return

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

        return height


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
        print(ob.heapHeight(N, arr))

# } Driver Code Ends
