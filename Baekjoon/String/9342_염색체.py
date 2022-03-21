import re

regex = re.compile('^[A-F]{0,1}A+F+C+[A-F]{0,1}$')

T = int(input())

testCase = [input() for _ in range(T)]

for tc in testCase:
    if regex.match(tc):
        print('Infected!')
    else:
        print('Good')