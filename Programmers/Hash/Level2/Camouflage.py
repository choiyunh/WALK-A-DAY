def solution(clothes):
    answer = 1
    dic = {}
    for cloth in clothes:
        if cloth[1] in dic:
            dic[cloth[1]] += 1
        else:
            dic[cloth[1]] = 1
    #print(dic)

    # 2+1 * 1+1 = 3
    # (yellow_hat, green_tur장ban, 0) (blue_sunglasses, 0)
    # 3*2 = 6
    # 6 - 1

    for num in dic.values():
        answer *= num + 1

    return answer - 1


print(solution([['yellow_hat', 'headgear'],
          ['blue_sunglasses', 'eyewear'],
          ['green_turban', 'headgear']]))

