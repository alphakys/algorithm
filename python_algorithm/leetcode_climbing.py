class Solution:
    sum_by_one = [1,1]
    sum_by_combi = []
    sum_by_two = [2]

    # 1 1 1 1 1 1
    # 1 2 1 1 1
    # 2 1 1 1 1
    # 1 1 2 1 1
    # 1 1 1 2 1
    # 1 1 1 1 2
    # 2 2 1 1
    # 2 1 2 1
    # 1 2 2 1
    # 1 1 2 2
    # 2 2 2
    #
    # 2 3 5 8 13 21  34
    #  1 2 3 5  8  13


    def climbStairs(self, n: int) -> int:
        step1 = 1
        step2 = 2





        while sums <= n:
            sums += step1
            cnt += 1

        print(f'cnt : {cnt}, sums : {sums}')


Solution().climbStairs(2)
