T = int(input())
 
for _ in range(T):
    s = input().replace(' ', '')
    alpha = [0] * 26
 
    for i in s:
        alpha[ord(i) - 97] += 1
 
    if alpha.count(max(alpha)) > 1:
        print('?')
    else:
        print(chr(97 + alpha.index(max(alpha))))
