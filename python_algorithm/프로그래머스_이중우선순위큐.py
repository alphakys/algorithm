operations = ["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]
operations = ["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]
answer = []
arr = []

front = 0
end = -1

for op in operations:
    if op == "D -1":
        arr.sort()
        front += 1
    elif op == "D 1":
        arr.sort()
        end -= 1
    else:
        arr.append(int(op.split(' ')[1]))
        end += 1

arr.sort()
print(arr)
print("f: ", front)
print("end: ", end)
