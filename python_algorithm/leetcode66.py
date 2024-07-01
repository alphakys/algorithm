if __name__ == '__main__':
    digits = [1, 9, 9]
    _sum = 0
    carry = 1
    for n in digits[::-1]:
        _sum = n + carry

        if _sum > 9:
            carry = _sum/10
            digits