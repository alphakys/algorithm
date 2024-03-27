class A:
    def __init__(self, name, parent=None):
        self.name = name
        self.parent = parent
        self.children = None

    def __del__(self):
        print("delete", self.name)


def main():
    a = A(name=1)
    b = A(name=2)

    a.children = b
    b.parent = a


    a = []
    a.append(a)
    print("end")

if __name__ == "__main__":
    # 출력이 어떻게 될까요?
    main()
