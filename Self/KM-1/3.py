# 221126

def solution(s, times):
    answer = [1, 1]

    for time in times:
        day = list(map(int, s.split(':')))
        t = list(map(int, time.split(':')))
        day_diff = 0

        limit = [12, 30, 24, 60, 60]
        for i in range(4, -1, -1):
            temp = day[i + 1] + t[i - 1]
            if i == 2:
                day_diff += temp // limit[i]
            elif i == 1:
                day_diff += (temp // limit[i]) * 30
                day_diff += (temp % limit[i]) - day[i + 1]
            elif i == 0:
                day[i] += day[i + 1] // limit[i]
                day[i + 1] = day[i + 1] % limit[i]
                continue
            day[i] += temp // limit[i]
            day[i + 1] = temp % limit[i]
        if day_diff > 1:
            answer[0] = 0
        answer[1] += day_diff
        s = ":".join(map(str, day))
    return answer
