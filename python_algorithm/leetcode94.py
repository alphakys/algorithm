class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import List, Optional


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        answer = []
        print(root)
        node, answer = self.order_util(root, answer)

        return answer

    def order_util(self, node, answer):
        if node.left != None:
            node, answer = self.order_util(node.left, answer)

        print(node.val)


        if node.right != None:
            node, answer = self.order_util(node.right, answer)

        answer.append(node.val)
        return node, answer


if __name__ == '__main__':
    Solution().inorderTraversal()
