def solution(numbers, hand):
    answer = ''
    left = [0, 0]
    right = [2, 0]

    for ix, n in enumerate(numbers):
        if n in [1, 4, 7]:
            left = [0, [7, 4, 1].index(n) + 1]
            answer += 'L'
        elif n in [3, 6, 9]:
            right = [2, [9, 6, 3].index(n) + 1]
            answer += 'R'
        else:
            next = [1, [0, 8, 5, 2].index(n)]
            distLeft = abs(next[0] - left[0]) + abs(next[1] - left[1])
            distRight = abs(next[0] - right[0]) + abs(next[1] - right[1])
            if distLeft > distRight:
                answer += 'R'
                right = next
            elif distLeft < distRight:
                answer += 'L'
                left = next
            else:
                answer += hand[0].upper()
                if hand == 'left':
                    left = next
                else:
                    right = next

    return answer


print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], 'left'))
