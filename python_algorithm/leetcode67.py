if __name__ == '__main__':
    a = "11"
    b = "11"
    i = len(a)
    j = len(b)
    stra = a[i - 1:i]
    strb = b[j - 1:j]
    _sum = 0
    carry = 0
    answer = []
    from io import StringIO
    while stra or strb or carry:
        _sum = (int(stra) if stra else 0) + (int(strb) if strb else 0) + carry
        carry = _sum // 2
        num = _sum % 2
        answer.append(str(num))
        text_io = StringIO()
        text_io.write(str(num))
        print(text_io.getvalue())
        i -= 1 if i > 0 else 0
        j -= 1 if j > 0 else 0

        stra = a[i - 1:i]
        strb = b[j - 1:j]

    "".join(answer[::-1])
    print(text_io.getvalue())