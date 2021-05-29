def solution(lottos, win_nums):
    numZero = lottos.count(0)
    cnt = 0

    for w in win_nums:
        if w in lottos:
            cnt += 1

    rank = [1, 2, 3, 4, 5, 6, 6]
    answer = [rank[7 - (cnt + numZero) - 1], rank[7 - cnt - 1]]

    return answer


print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))
