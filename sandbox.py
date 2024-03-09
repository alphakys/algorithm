import numpy as np


class Category:

    def __init__(self, val: str, child: list):
        self.val = val
        self.child_categories = child


category = ["a", "b", "c", "d", "e"]

relation = ["a b", "b c", "c d", "c e"]

member = ["A a", "B b", "C c", "D d", "E e"]

article = ["a", "a b", "c", "c d", "c e"]

from collections import defaultdict

relation_dict = defaultdict(lambda: [])
member_dict = defaultdict(lambda: [])

for r in relation:
    parent, child = r.split(' ')
    relation_dict[parent].append(child)

print("relations : ", relation_dict)

for m in member:
    name, category = m.split(' ')
    member_dict[name].append(category)

print("members : ", member_dict)

# article = [articles.extend(a.split(' ')) for a in article]

print(article)
print()


def seek_parent(category, parents_categories=set()):
    for k, v in relation_dict.items():
        if category in v:
            parents_categories.add(k)
            seek_parent(k, parents_categories)

    return parents_categories


def seek_member(article):
    for name, arti in member_dict.items():
        if article in arti:
            return name, arti


publish_list = set()

answer = []
for _ in article:
    split_article = _.split(' ')

    cnt = 0
    parents = []
    for a in split_article:
        name, arti = seek_member(a)
        publish_list.add(name)

        parent_cate = seek_parent(arti[0])

        for p in parent_cate:
            name, arti = seek_member(p)
            publish_list.add(name)

    answer.append(len(publish_list))

print(answer)

exit()

l = []

for i in range(1000):
    for j in range(1000):
        print(1, end=' ')
    print()

exit()
validation_array_list = [[1]]

for _ in range(7):
    validation_array_list.append([1 for i in range(2 << _)])

square = \
    [
        [1, 1, 0, 0, 0, 0, 1, 1, ],
        [1, 1, 0, 0, 0, 0, 1, 1, ],
        [0, 0, 0, 0, 1, 1, 0, 0, ],
        [0, 0, 0, 0, 1, 1, 0, 0, ],
        [1, 0, 0, 0, 1, 1, 1, 1, ],
        [0, 1, 0, 0, 1, 1, 1, 1, ],
        [0, 0, 1, 1, 1, 1, 1, 1, ],
        [0, 0, 1, 1, 1, 1, 1, 1]
    ]

square = np.array(square)


def split_matrix(left, right):
    # mid = (left + right) // 2

    # 4
    # N = right // 2
    mid = (left + right) // 2

    is_valid = check_valid_list(left, mid, square)
    is_valid = check_valid_list(mid, right, square)

    if is_valid:
        # blue square
        pass
    else:
        # not blue square
        # recursion
        split_matrix(left, mid)
        pass

    # print(li)
    #             print(check_arr)
    #             print("Wrong Let's split")
    #             print()
    #             split_matrix(left, mid)

    # while True:
    #     pass

    return


def check_valid_list(start, end, arr):
    print(f"start : {start} end : {end}")
    check_arr = validation_array_list[(end - start) >> 1]

    for _ in range(2):

        if _ == 0:
            second_dimension_start = start
            second_dimension_end = end
        else:
            second_dimension_start = end
            second_dimension_end = end * 8

        for line in square[start:end]:
            li = line[second_dimension_start:second_dimension_end]
            # [0:4] [5:8]이 나와야 함.
            if all(li == check_arr):
                print(li)
                print("correct!!")
                print()
                continue
            else:
                print("Wrong")
                print(li)
                print()
                break

    return True


N = 8

split_matrix(0, N)
