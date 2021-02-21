def solution(n):
    binNum = str(bin(n))[2:]
    cnt = 0
    for a in binNum:
        if a == '1':
            cnt += 1

    answer = n
    while True:
        answer += 1
        binAns = str(bin(answer))[2:]
        cnt2 = 0

        for b in binAns:
            if b == '1':
                cnt2 += 1
        if cnt == cnt2:
            break

    return answer


print(solution(78))
