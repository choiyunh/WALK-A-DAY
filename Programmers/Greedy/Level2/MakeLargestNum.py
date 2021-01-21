def solution(number, k):
    temp = ''

    while (k > 0):
        flag = 0
        for i in range(0, len(number) - 1):
            if number[i] < number[i + 1]:
                temp += number[0:i]
                temp += number[i + 1:len(number)]
                number = temp
                temp = ''
                k -= 1
                flag = 1
                break

        if flag == 0:
            k -= 1
            number = number[:-1]

    return number


print(solution("1294", 2))
