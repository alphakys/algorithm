from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"ListNode : {self.val}"


def loop_linked_list(head):
    while head:
        print(head.val)
        head = head.next


class Solution:

    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:


if __name__ == '__main__':
    inputs = [1, 2, 3, 3, 3, 3, 3]

    root_node = ListNode(inputs[0])
    head = root_node
    for n in inputs[1:]:
        while head.next:
            head = head.next
        head.next = ListNode(n)
    Solution().deleteDuplicates(root_node)

    # def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     root = head
    #
    #     while root:
    #         next_node = root.next
    #         while next_node and root.val == next_node.val:
    #             next_node = next_node.next
    #         root.next = next_node
    #         root = root.next
    #     loop_linked_list(head)
