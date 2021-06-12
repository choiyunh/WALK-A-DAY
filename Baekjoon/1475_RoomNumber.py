def solution(N):
    cnt = [0, 0, 0, 0, 0, 0, 0, 0, 0]  # 0~8

    for a in N:
        i = int(a)
        if i == 9:
            cnt[6] += 1
        else:
            cnt[i] += 1
    cnt[6] = (cnt[6] + 1) // 2
    return max(cnt)


N = input()

print(solution(N))
