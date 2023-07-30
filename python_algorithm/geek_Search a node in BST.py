# Your task is to complete this function

class BST:

    def order_util(self, root, key, answer):
        if root.data < key:
            if root.right:
                answer = self.order_util(root.right, key, answer)
            else:
                if root.data == key:
                    answer = 1
                else:
                    answer = 0
        elif root.data > key:
            if root.left:
                answer = self.order_util(root.left, key, answer)
            else:
                if root.data == key:
                    answer = 1
                else:
                    answer = 0
        else:
            answer = 1

        return answer

    # Function to search a node in BST.
    def search(self, node, x):
        return self.order_util(node, x, None)


# code here


# {
# Driver Code Starts
class Node:
    """ Class Node """

    def __init__(self, value):
        self.left = None
        self.data = value
        self.right = None


class Tree:
    def createNode(self, data):
        return Node(data)

    def insert(self, node, data):
        if node is None:
            return self.createNode(data)
        else:
            if data < node.data:
                node.left = self.insert(node.left, data)
            else:
                node.right = self.insert(node.right, data)
            return node

    def traverseInorder(self, root):
        if root is not None:
            print(root.data, end=" ")
            self.traverseInorder(root.left)
            self.traverseInorder(root.right)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = input().strip().split()
        root = None
        tree = Tree()
        root = tree.insert(root, int(arr[0]))
        for j in range(1, n):
            root = tree.insert(root, int(arr[j]))
        # tree.traverseInorder(root)
        num = int(input())
        find = BST()
        if find.search(root, num):
            print(1)
        else:
            print(0)

# } Driver Code Ends
