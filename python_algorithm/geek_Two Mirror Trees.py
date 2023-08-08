# User function Template for python3

'''
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''


class Solution:
    def areMirror(self, root1, root2):
        '''
        :param root1,root2: two root of the given trees.
        :return: True False

        '''
        if root1.data != root2.data:
            return False

        return self.order_util(root1, []) == self.order_util2(root2, [])

    def order_util(self, root, arr):

        if root.left:
            self.order_util(root.left, arr)

        arr.append(root.data)

        if root.right:
            self.order_util(root.right, arr)

        return arr

    def order_util2(self, root, arr):

        if root.right:
            self.order_util2(root.right, arr)

        arr.append(root.data)

        if root.left:
            self.order_util2(root.left, arr)

        return arr

    def is_same(self, root1, root2):

        if root1.left and root2.right:
            if root1.left.data != root2.right.data:
                return False
        else:
            print(1)
            return False

        if root1.right and root2.left:
            if root1.right.data != root2.left.data:
                return False
        else:
            print(2)
            return False

        return True

    def mirror(self, root1, root2):
        if root1.left and root2.left:
            self.mirror(root1.left, root2.left)

        if root1.right and root2.right:
            self.mirror(root1.right, root2.right)

        if (root1.left and root2.left) or (root1.right and root2.right):
            # print(
            #     f'r1 left : {root1.left.data} r2 right : {root2.right.data} r1 right {root1.right.data} r2 left {root2.left.data}')
            print(root1.data, '', root2.data)
            if root1.data != root2.data:
                return False


# {
# Driver Code Starts
# Contributed by Sudarshan Sharma
from collections import deque


# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    # Corner Case
    if (len(s) == 0 or s[0] == "N"):
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while (size > 0 and i < len(ip)):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if (currVal != "N"):
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if (i >= len(ip)):
            break
        currVal = ip[i]

        # If the right child is not null
        if (currVal != "N"):
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        str1 = input()
        str2 = input()
        root1 = buildTree(str1)
        root2 = buildTree(str2)
        if Solution().areMirror(root1, root2) == True:
            print(1)
        else:
            print(0)

# } Driver Code Ends