def solution(files):
    dic = {}

    for file in files:
        flag = True
        startNum = 0
        for i in range(len(file)):
            if flag and file[i].isdigit():
                dic[file] = [file[:i]]
                startNum = i
                flag = False
            if not flag:
                if not file[i].isdigit():
                    dic[file].append(file[startNum:i])
                    dic[file].append(file[i:])
                    break
                elif i == len(file) - 1:
                    dic[file].append(file[startNum:])
                    break
    print(dic)
    dic = sorted(dic.items(), key=lambda x: (x[1][0].lower(), int(x[1][1])))

    answer = [d[0] for d in dic]
    return answer


print(solution(["img12", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]))
