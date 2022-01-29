def dfs(num, arr):
    arr[num] = -2
    for i in range(len(arr)):
        if num == arr[i]:
            dfs(i, arr)


n = int(input())
parents = list(map(int, input().split()))
target = int(input())

dfs(target, parents)
result = 0

for i in range(len(parents)):
    if parents[i] != -2 and i not in parents:
        result += 1

print(result)
