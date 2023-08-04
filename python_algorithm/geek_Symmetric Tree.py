# User function Template for python3

#        5
#    /      \
#   10       10
#  /  \     /  \
# 20  30   30   20

#        5
#    /      \
#   10       20
#  /  \     /  \
# 30  40   50   60


# 1  1 2 2 1 1 2  2
class Solution:
    # return true/false denoting whether the tree is Symmetric or not
    def isSymmetric(self, root):

        if not root:
            return True

        if (root.left and not root.right) or (not root.left and root.right):
            return False
        elif not root.left and not root.right:
            return True

        left_subtree = self.levelOrder(root.left, 'l')
        right_subtree = self.levelOrder(root.right, 'r')

        # print(left_subtree)
        # print(right_subtree)

        if left_subtree == right_subtree:
            return True
        else:
            return False

    def levelOrder(self, root, subtree):

        root_l = [root]
        child_list = []
        answer = deque()
        traversal_list = []
        while root_l:
            for node in root_l:
                if subtree == 'r':
                    answer.appendleft(node.data)
                else:
                    answer.append(node.data)

                if node.left:
                    child_list.append(node.left)
                if node.right:
                    child_list.append(node.right)

            root_l = child_list
            child_list = []
            traversal_list.extend(answer)
            answer.clear()

        return traversal_list

# Your Code Here


# {
# Driver Code Starts
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
        ob = Solution()
        if ob.isSymmetric(root):
            print("True")
        else:
            print("False")

# } Driver Code Ends
