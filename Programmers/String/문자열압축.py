def solution(s):
    length = []

    if len(s) == 1:
        return 1

    for cut in range(1, len(s) // 2 + 1):
        cnt = 1
        temp = s[:cut]
        result = ""
        for i in range(cut, len(s), cut):
            if s[i:i + cut] != temp:
                if cnt != 1:
                    result += str(cnt)
                result += temp
                temp = s[i:i + cut]
                cnt = 1
            else:
                cnt += 1
        if cnt != 1:
            result += str(cnt)
        result += temp
        length.append(len(result))

    return min(length)
