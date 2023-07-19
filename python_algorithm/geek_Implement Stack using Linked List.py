class MyStack:

    # class StackNode:

    # # Constructor to initialize a node
    def __init__(self):
        self.head = None
        # self.next = None

    # Function to push an integer into the stack.
    def push(self, data):
        node = StackNode(data)
        tmp = self.head
        if tmp:
            while tmp.next:
                tmp = tmp.next
            tmp.next = node
        else:
            self.head = node

        return self.head

    # Add code here

    # Function to remove an item from top of the stack.
    def pop(self):
        if self.head:
            n = self.head

            del n
            print(self.head)
            return
            # curr = n
            while n.next:
                n = n.next
            val = n.data
            # print(id(n))
            n = None
            return val
        else:
            return -1

    def printList(self, node):
        temp = node
        while (temp):
            print(temp.data, end=" ")
            temp = temp.next

# Add code here


# {
# Driver Code Starts


class StackNode:

    # Constructor to initialize a node
    def __init__(self, data):
        self.data = data
        self.next = None


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = MyStack()
        q = int(input())
        q1 = list(map(int, input().split()))
        i = 0
        while (i < len(q1)):
            if (q1[i] == 1):
                s.push(q1[i + 1])
                i = i + 2
            elif (q1[i] == 2):
                print(s.pop(), end=" ")
                i = i + 1
            elif (s.isEmpty()):
                print(-1)
        print()
    print("list print")
    s.printList(s.head)

# } Driver Code Ends


# class StackNode:
#
#     def __init__(self):
#         self.arr = []
#         self.pos = -1
#
#     def push(self, val):
#         self.arr.append(val)
#         self.pos += 1
#
#     def pop(self):
#
#         if self.is_empty():
#             return
#
#         val = self.arr[self.pos]
#         del self.arr[self.pos]
#         self.pos -= 1
#         return val
#
#     def is_empty(self):
#         if self.pos < 0:
#             print("stack이 비었습니다.")
#             return True
#         return False
#
# s = StackNode()
#
# s.pop()
# s.push(1)
# s.pop()
# s.pop()
# s.push(2)
# s.push(3)
# s.push(11)
# s.push(30)
# s.pop()
# print(s.arr)