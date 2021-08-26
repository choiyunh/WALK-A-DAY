nums = [3, 2, 4]
target = 6

temp = {nums[0]: 0}
print(3 in temp.values())

for i in range(1, len(nums)):
    if target - nums[i] in temp:
        print([temp[target - nums[i]], i])
    else:
        temp[nums[i]] = i
