# User function Template for python3


class Solution:
    # Function to check whether a Binary Tree is BST or not.
    def inorder(self, root, arr, answer):
        if root.left:
            arr, answer = self.inorder(root.left, arr, answer)

        if answer == 0:
            return arr, answer

        if arr != []:
            if arr[-1] >= root.data:
                return arr, 0

        arr.append(root.data)

        if root.right:
            arr, answer = self.inorder(root.right, arr, answer)

        return arr, answer

    def isBST(self, root):

        arr, answer = self.inorder(root, [], 1)

        return answer
    # def order_util(self, root, answer, head):
    #
    #     if root.left and root.left.data <= root.data:
    #         if root.data == root.left.data:
    #             return 0
    #         else:
    #             answer = self.order_util(root.left, answer)
    #     elif root.left and root.left.data > root.data:
    #         return 0
    #
    #     if root.right and root.right.data >= root.data:
    #         if root.data == root.right.data:
    #             return 0
    #         else:
    #             answer = self.order_util(root.right, answer)
    #     elif root.right and root.right.data < root.data:
    #         return 0
    #
    #     return answer
    # def isBST(self, root):
    #
    #     if not root:
    #         return 0
    #
    #     return self.order_util(root, 1, root.data)


        #     #
        #     #         10
        #     #     5        18
        #     #   2   9    15 19
        #     #    4 8    1


    # 틀림


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