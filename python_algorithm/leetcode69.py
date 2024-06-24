def binary_search(arr, target):
    left = 0
    right = len(arr)
    mid = (left + right) // 2

    while left < right:
        if arr[mid] == target:
            break
        elif arr[mid] > target:
            right = mid
        else:
            left = mid + 1

        mid = (left + right) // 2

    return mid


class Solution:
    def mySqrt(self, x: int) -> int:
        if x <=1:
            return x

        left = 0
        right = x // 2
        mid = (left + right) // 2

        while left < right:
            pow_num = mid * mid
            next_pow = (mid + 1) * (mid + 1)
            if pow_num == x:
                break
            if pow_num < x < next_pow:
                break
            elif pow_num > x:
                right = mid
            else:
                left = mid + 1

            mid = (left + right) // 2

        return mid


if __name__ == '__main__':
    x = 2
    import math
    print(math.sqrt(x))
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
