def solution(record):
    answer = []
    enterRecord = {}

    for r in record:
        splitRecord = r.split()

        if splitRecord[0] in ["Enter", "Change"]:
            enterRecord[splitRecord[1]] = enterRecord.get(
                splitRecord[0], splitRecord[2])

    for r in record:
        splitRecord = r.split()

        if splitRecord[0] == "Enter":
            answer.append(enterRecord[splitRecord[1]] + "님이 들어왔습니다.")
        elif splitRecord[0] == "Leave":
            answer.append(enterRecord[splitRecord[1]] + "님이 나갔습니다.")

    return answer
