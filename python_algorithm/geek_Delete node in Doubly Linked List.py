# User function Template for python3

'''class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
'''


class Solution:

    def deleteNode(self, head, x):

        if x == 1:
            tmp = head.next
            tmp.prev = None
            return tmp

        position = 1
        curr = head
        while head.next and position < x:
            # print("h", id(head))
            curr = head
            head = head.next
            position += 1

        curr.next = head.next
        if head.next:
            head.next.prev = curr

        return curr


# Code here
#     def deleteNode(self, head, x):
#         # Code here
#         curNode = head
#         for i in range(1, x):
#             curNode = curNode.next
#
#         if x == 1:
#             head = head.next
#             head.prev = None
#         elif curNode.next:
#             curNode.prev.next = curNode.next
#             curNode.next.prev = curNode.prev
#         else:
#             curNode.prev.next = None
#
#         return head



    # {
# Driver Code Starts
# Initial Template for Python 3


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, new_data):
        new_node = Node(new_data)
        new_node.next = None
        if self.head is None:
            new_node.prev = None
            self.head = new_node
            self.tail = self.head
            return
        self.tail.next = new_node
        self.tail.next.prev = self.tail
        self.tail = self.tail.next

    def printList(self, node):
        while (node.next is not None):
            node = node.next
        while node.prev is not None:
            node = node.prev
        while (node is not None):
            print(node.data, end=" ")
            node = node.next
        print()


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        llist = DoublyLinkedList()
        for e in arr:
            llist.append(e)
        pos = int(input())
        Solution().deleteNode(llist.head, pos)
        llist.printList(llist.head)
# Contributed by: Harshit Sidhwa


# } Driver Code Ends
