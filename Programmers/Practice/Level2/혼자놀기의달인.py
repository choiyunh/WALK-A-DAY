# 2022/10/20 혼자놀기의 달인

def solution(cards):
    answer = 0
    lenCards = len(cards)
    for card in cards:
        visited = [False for _ in range(lenCards)]
        next = card
        cnt1 = 0
        while not visited[next - 1]:
            visited[next - 1] = True
            cnt1 += 1
            next = cards[next - 1]
        target = []
        for i in range(lenCards):
            if not visited[i]:
                target.append(cards[i])

        cnt2 = 0
        for t in target:
            next = t
            cnt3 = 0
            while not visited[next - 1]:
                visited[next - 1] = True
                cnt3 += 1
                next = cards[next - 1]
            cnt2 = max(cnt2, cnt3)
        answer = max(answer, cnt1 * cnt2)
    return answer