# 221102 두 큐 합 같게 만들기

def solution(queue1, queue2):
    answer = 0
    queue3 = queue1 + queue2
    target = sum(queue3) // 2
    sumQ1, sumQ2 = sum(queue1), sum(queue2)

    i, j = 0, len(queue1)
    while i < len(queue3) and j < len(queue3):
        if sumQ1 < sumQ2:
            sumQ1 += queue3[j]
            sumQ2 -= queue3[j]
            j += 1
        elif sumQ1 > sumQ2:
            sumQ1 -= queue3[i]
            sumQ2 += queue3[i]
            i += 1
        else:
            return answer
        answer += 1
    return -1