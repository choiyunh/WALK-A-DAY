import sys


def inputStr():
    return sys.stdin.readline().rstrip()


def isPalindrome(start, end, cnt):
    if cnt == 2:
        return cnt
    while start <= end:
        if string[start] != string[end]:
            a = isPalindrome(start + 1, end, cnt + 1)
            b = isPalindrome(start, end - 1, cnt + 1)
            return a if a <= b else b
        start += 1
        end -= 1
    else:
        return cnt


for _ in range(int(input())):
    string = inputStr()
    print(isPalindrome(0, len(string) - 1, 0))
