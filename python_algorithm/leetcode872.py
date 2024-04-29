# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from collections import deque


class Solution:

    def setup(self):
        nodes = [3, 5, 1, 6, 2, 9, 8, None, None, 7, 4]

        root = TreeNode(3)
        print(root)
        q = deque()
        q.append(root)

        while q.len() > 0:
            curr = q.popleft()

            for n in nodes[1:]:

                if not curr.left:
                    curr.left = TreeNode(n)
                    q.append(curr.left)
                    continue

                if not curr.right:
                    curr.right = TreeNode(n)
                    q.append(curr.right)
                    continue



    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        pass


Solution().setup()
