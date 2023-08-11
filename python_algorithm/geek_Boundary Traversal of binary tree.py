# User function Template for python3

'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''


#         1
#       /   \
#      2     3
#     / \   / \
#    4   5 6   7
#       / \
#      8   9
#

# 1 2 4 8 9 6 7 3


#             1
#            /
#           2
#         /  \
#        4    9
#      /  \    \
#     6    5    3
#              /  \
#             7     8
#
# 1 2 4 6 5 7 8


#                 4
#          10
#      5         5
#        6     7
#      8     8     8
#   11     3   4      1
#  3     8 6     11 11
# 5  8


class Solution:
    def levelorder_util(self, root):
        root_list = [root]
        child_list = []
        traversal_list = []

        while root_list:

            for root in root_list:
                traversal_list.append(root.data)
                if root.left:
                    child_list.append(root.left)
                if root.right:
                    child_list.append(root.right)

            print(child_list[0].data, child_list[-1].data)
            root_list = child_list
            child_list = []

        return traversal_list

    def order_util(self, root, arr):
        if root.left:
            self.order_util(root.left, arr)

        if root.right:
            self.order_util(root.right, arr)

        if not root.left and not root.right:
            arr.append(root.data)
        return arr

    def printBoundaryView(self, root):

        if root.left:
            root_list = [root.left]
            child_list = []
            traversal_list = []

            while root_list:

                for node in root_list:
                    traversal_list.append(node.data)
                    if node.left:
                        child_list.append(node.left)
                    if node.right:
                        child_list.append(node.right)

                print(child_list[0].data)
                root_list = child_list
                child_list = []

        if root.right:
            root_list = [root.right]
            child_list = []
            traversal_list = []

            while root_list:

                for node in root_list:
                    traversal_list.append(node.data)
                    if node.left:
                        child_list.append(node.left)
                    if node.right:
                        child_list.append(node.right)

                print(child_list[-1].data)
                root_list = child_list
                child_list = []


# Code here


# {
# Driver Code Starts
# Initial Template for Python 3

# function should return a list containing the boundary view of the binary tree
# {
#  Driver Code Starts
import sys

import sys

sys.setrecursionlimit(100000)
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


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        obj = Solution()
        res = obj.printBoundaryView(root)
        for i in res:
            print(i, end=" ")
        print('')
# } Driver Code Ends
