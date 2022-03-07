n = int(input())
nums = list(map(int,input().split()))

for x in range(1, min(nums) + 1):
    flag = True
    for num in nums:
        if num % x != 0:
            flag = False
    if flag:
        print(x)

