class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    # Function to insert a node at the beginning of the linked list.
    def insertAtBegining(self, head, x):
        # Create Node
        node = Node(x)
        node.next = head

        return node
    # code here

    # Function to insert a node at the end of the linked list.
    def insertAtEnd(self, head, x):

        # head.next를 통해 다음 노드에 접근 그리고 값이 없을 때까지 loop
        if not head:
            head = Node(x)
            return head

        n = head
        while n.next:
            n = n.next
        n.next = Node(x)
        return head

# code here s

def main() -> None:


if __name__ == '__main__':
    main()
