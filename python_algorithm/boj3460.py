import sys

T = int(sys.stdin.readline())
n = int(sys.stdin.readline())


N = input(0)
N = input()
[1]*10
a = []
a[0]
a[1]
bin(2)
bin(3)
8
a = 8
a
q = a
q
r = 0
divisor = 2
while q>1:
    q = q/2
    print(q)

while q>1:
    q = int(q/2)
    print(q)

q = 8
r = None
while q>1:
    q = int(q/2)
    r = int(q%2)
    print(f'{q}, {r}')

q = 8
r = None
bit = ''
while q>1:
    q = int(q/2)
    r = int(q%2)
    bit += r
    print(f'{q}, {r}')
    print(bit)

q = 8
r = None
bit = ''
while q>1:
    q = int(q/2)
    r = int(q%2)
    bit += str(r)
    print(f'{q}, {r}')
    print(bit)

q = 8
r = None
bit = ''
while q>1:
    q = int(q/2)
    r = int(q%2)
    bit += str(r)
    print(f'{q}, {r}')
print(bit)

q = 8
r = None
bit = ''
while q>1:
    q = int(q/2)
    r = int(q%2)
    bit += str(r)
    print(f'{q}, {r}')
print(bit[-1:])

q = 8
r = None
bit = ''
while q>0:
    q = int(q/2)
    r = int(q%2)
    bit += str(r)
    print(f'{q}, {r}')


q = 2
r = None
bit = ''
while q>1:
    q = int(q/2)
    r = int(q%2)
    bit += str(r)
    print(f'{q}, {r}')


q = 8
r = None
bit = ''
while q>1:
    q = int(q/2)
    r = int(q%2)
    bit += str(r)
    print(f'{q}, {r}')


q = 9
r = None
bit = ''
while q>1:
    q = int(q/2)
    r = int(q%2)
    bit += str(r)
    print(f'{q}, {r}')


q = 9
r = None
bit = ''
while q>1:
    r = int(q%2)
    q = int(q / 2)
    bit += str(r)
    print(f'{q}, {r}')


q = 9
r = None
bit = ''
while q>1:
    r = int(q%2)
    q = int(q / 2)
    bit += str(r)
    print(f'{q}, {r}')
print(str(1) + bit)

divider = lambda x: x%2
divider(7)
def divider(q):
    r = q % 2
    if r > 1:
        divider(r)
    return r

def divider(q):
    r = q % 2
    print(f'recursive : {r}')
    if r > 1:
        divider(r)
    return r

def divider(q):
    r = q % 2
    print(f'recursive : {r}')
    if r > 1:
        divider(q/2)
    return r

def divider(q):
    q = q / 2
    print(f'recursive : {q%2}')
    if q > 1:
        divider(q/2)
    return q%2

def divider(q):
    q = q / 2
    print(f'recursive : {int(q%2)}')
    if q > 1:
        divider(q/2)
    return q%2

divider(10)
divider(8)