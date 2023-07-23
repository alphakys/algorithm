# User function Template for python3


class Solution:
    # Function to check whether a Binary Tree is BST or not.
    def isBST(self, root):
        root.head = None
        root_list = [root]
        child_list = []
        #     #
        #     #         10
        #     #     5        18
        #     #   2   9    15 19
        #     #    4 8    1

        #     #
        #     #          3
        #     #     1         5
        #     #       2    4    8
        #     #               7
        #                   6

        #     #
        #     #          8
        #     #      4         11
        #     #   1     7    9
        #     #    2   6
        #

        is_bst = 1

        while root_list:

            for root in root_list:

                if root.left:
                    root.left.head = root
                    if root.data <= root.left.data:
                        is_bst = 0
                        child_list = []
                        break
                    elif root.head is not None:
                        if root.head.data >= root.left.data:
                            is_bst = 0
                            child_list = []
                            break
                    else:
                        child_list.append(root.left)

                if root.right:
                    root.right.head = root
                    if root.data >= root.right.data:
                        is_bst = 0
                        child_list = []
                        break
                    # elif root.head is not None:
                    #     if root.head.data >= root.left.data:
                    #         is_bst = 0
                    #         child_list = []
                    #         break
                    else:
                        child_list.append(root.right)

            root_list = child_list
            child_list = []

        return is_bst

# code here


# {
# Driver Code Starts
# Initial Template for Python 3
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
        if Solution().isBST(root):
            print(1)
        else:
            print(0)
# } Driver Code Ends