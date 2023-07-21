# User function Template for python3


'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
'''


# Function to return a list containing the preorder traversal of the tree.

def order_util(root, arr):

    arr.append(root.data)
    if root.left:
        order_util(root.left, arr)

    if root.right:
        order_util(root.right, arr)

    return arr

def preorder(root):
    arr = []
    if not root:
        return

    return order_util(root, arr)


# 다른 예제!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11


# def preorderUtil(root, res):
#     # preorder traversal works on Root Left Right.
#
#     # if root is null then we simply return.
#     if root is None:
#         return
#
#     # first, we store the data at root in a list.
#     res.append(root.data)
#     # then we call the recursive function for left subtree.
#     preorderUtil(root.left, res)
#     # then we call the recursive function for right subtree.
#     preorderUtil(root.right, res)
#
#
# # Function to return a list containing the preorder traversal of the tree.
# def preorder(root):
#     res = []
#     preorderUtil(root, res)
#     # returning the list.
#     return res






# {
# Driver Code Starts
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
        res = preorder(root)
        for i in res:
            print(i, end=" ")
        print()

# } Driver Code Ends
