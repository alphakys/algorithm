# User function Template for python3

from collections import deque

dq = deque()


# Function to return a list containing the level order traversal in spiral form.
def findSpiral(root):
    if not root:
        return

    dq.append(root.data)
    height = 1
    root_list = [root]
    child_list = []
    traverse_list = []

    while root_list:

        for node in root_list:
            if height % 2 == 0:
                if node.left:
                    child_list.append(node.left)
                    dq.appendleft(node.left.data)
                if node.right:
                    child_list.append(node.right)
                    dq.appendleft(node.right.data)
            else:
                if node.left:
                    child_list.append(node.left)
                    dq.append(node.left.data)
                if node.right:
                    child_list.append(node.right)
                    dq.append(node.right.data)
        root_list = child_list
        child_list = []
        traverse_list.extend(dq)
        dq.clear()
        height += 1
    return traverse_list

    #        10
    #   3          15
    # 0   7      11
    #    4         14
    #      6


# Code here


# {
# Driver Code Starts
# Initial Template for Python 3

# Initial Template for Python 3


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
        result = findSpiral(root)
        for value in result:
            print(value, end=" ")
        print()

# } Driver Code Ends
