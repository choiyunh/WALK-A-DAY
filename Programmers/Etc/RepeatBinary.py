def solution(files):
    cntZero = 0
    cntConver = 0

    while files != '1':
        cntZero += files.count('0')
        files = format(len(files.replace('0', '')), 'b')
        cntConver += 1
    print(files)
    answer = [cntConver, cntZero]

    return answer


print(solution("110010101001"))
