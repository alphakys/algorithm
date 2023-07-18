# your task is to complete this function
# function should return true/1 if both
# are identical else return false/0
'''
# Node Class
class node:
    def __init__(self, val):
        self.data = val
        self.next = None

'''


# Function to check whether two linked lists are identical or not.
def areIdentical(head1, head2):
    # arr1 = []
    # arr2 = []

    # 더빠름
    while head1 and head2:
        if head1.data != head2.data:
            return 0
        else:
            head1 = head1.next
            head2 = head2.next

    if any([head1, head2]):
        return 0
    else:
        return 1

    # arr1 = []
    # arr2 = []
    # while head1:
    #     arr1.append(head1.data)
    #     head1 = head1.next
    #
    # while head2:
    #     arr2.append(head2.data)
    #     head2 = head2.next
    #
    # return arr1 == arr2
# Code here


# {
# Driver Code Starts
# Node Class
class node:
    def __init__(self, val):
        self.data = val
        self.next = None


# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None

    def insert(self, val):
        new_node = node(val)
        new_node.data = val
        new_node.next = self.head
        self.head = new_node


def printList(head):
    while head:
        print(head.data, end=' ')
        head = head.next
    print()


def createList(arr, n):
    lis = Linked_List()
    for i in range(n):
        lis.insert(arr[i])
    return lis.head


if __name__ == '__main__':
    # t = int(input())
    # for i in range(t):

    n = int(input())
    arr = list(map(int, input().strip().split()))
    head1 = createList(arr, n)
    n = int(input())
    arr = list(map(int, input().strip().split()))
    head2 = createList(arr, n)
    if (areIdentical(head1, head2)):
        print('Identical')
    else:
        print('Not identical')
# Contributed by: Harshit Sidhwa
# } Driver Code Ends