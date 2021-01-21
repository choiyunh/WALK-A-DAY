def solution(n):
    answer = 0
    temp = ""

    while (n > 0):
        temp += (str)(n % 3)
        n = (int)(n / 3)

    # 0021 -> 3^3*0 + 3^2*0 + 3^1*2 + 3^0*1
    b = len(temp) - 1
    for a in temp:
        answer += (int)(a) * (3 ** b)  # a*3^b
        b -= 1
    return answer


print(solution(45))

# 45/3 =  15 0
# 15/3 =  5  0
# 5/3  =  1  2
# 1/3  =  0  1
