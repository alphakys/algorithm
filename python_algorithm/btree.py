MAX_KEYS = 5
MAX_CHILDREN = 5


class BtreeNode:

    # initialize는 btree의 메타정보를 생성한다.
    def __init__(self, is_leaf=False):
        self.len = 0
        self.key = [0] * MAX_KEYS
        self.child = [None] * MAX_CHILDREN
        self.leaf = is_leaf


class Btree:

    def __init__(self):
        self.root = BtreeNode()

    def insert_key(self, val):
        if len == MAX_KEYS:
            while val in self.root.key:

            self.split_child()
        else:
            index = self.root.len
            self.root.key[index] = val
            self.root.len += 1

    def split_child(self):
        pass

btree = Btree()

print(btree)
