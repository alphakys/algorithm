class Solution:
    def mySqrt(self, x: int) -> int:
        i = 0
        while True:
            if i ** 2 == x:
                return i
            elif i ** 2 < x < (i + 1) ** 2:
                return i
            i += 1


if __name__ == '__main__':
    x = 1
    """
    어떤 값에 제곱을 해야 x가 나오니??
    a ** 2 = x
    """
    answer = Solution().mySqrt(x)
    print(answer)


"""
18의 약수
1, 2 ,3, 6, 9, 18
square 라는 것은 두 수의 곱이지만 
단지 그 수가 integer가 아닐 때를 의미함.

그렇다면 약수의 중간 값이 square이다.

1, 2, 4, 5, 10, 20
"""