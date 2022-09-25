from collections import defaultdict


def solution(inp_str):
    answer = set()
    special = "~!@#$%^&*"
    checkGroup = set()
    checkNum = defaultdict(int)
    count = 0
    length = len(inp_str)

    if not (8 <= length <= 15):
        answer.add(1)
    for i in range(length):
        checkNum[inp_str[i]] += 1
        if 65 <= ord(inp_str[i]) <= 90:
            checkGroup.add(0)
        elif 97 <= ord(inp_str[i]) <= 122:
            checkGroup.add(1)
        elif inp_str[i].isdigit():
            checkGroup.add(2)
        elif inp_str[i] in special:
            checkGroup.add(3)
        else:
            answer.add(2)

        if i < length - 1 and inp_str[i] == inp_str[i + 1]:
            count += 1
        else:
            count = 0
        if count >= 3:
            answer.add(4)

    if len(checkGroup) < 3:
        answer.add(3)
    for v in checkNum.values():
        if v >= 5:
            answer.add(5)
    if len(answer) == 0:
        return [0]
    return sorted(list(answer))
