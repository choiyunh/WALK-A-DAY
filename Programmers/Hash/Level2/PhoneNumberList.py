def solution(phone_book):
    answer = True
    phone_book.sort()
    for i in range(0, len(phone_book)-1):
        if phone_book[i] == phone_book[i + 1][:len(phone_book[i])]:
            answer = False
    return answer


print(solution(['119', '97674223', '1195524421']))