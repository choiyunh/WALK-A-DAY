def solution(files):
    answer = []

    for file in files:
        flag = True
        startNum = 0
        tmp = []
        for i in range(len(file)):
            if flag and file[i].isdigit():
                tmp = [file[:i]]
                startNum = i
                flag = False
            if not flag:
                if not file[i].isdigit():
                    tmp.append(file[startNum:i])
                    tmp.append(file[i:])
                    break
                elif i == len(file) - 1:
                    tmp.append(file[startNum:])
                    break
        answer.append(tmp)

    answer.sort(key=lambda x: (x[0].lower(), int(x[1])))
    return [''.join(a) for a in answer]


print(solution(["img12", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]))
