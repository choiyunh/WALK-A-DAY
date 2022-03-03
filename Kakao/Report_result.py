def solution(id_list, report, k):
    answer = [0 for _ in range(len(id_list))]
    report_people = [[] for _ in range(len(id_list))]

    for rep in report:
        a, b = rep.split(" ")
        report_people[id_list.index(b)].append(a)
    
    for i in range(len(report_people)):
        report_people[i] = set(report_people[i])
        if len(report_people[i]) >= k:
            for people in report_people[i]:
                answer[id_list.index(people)] += 1
    return answer
