class Solution:
    def interpret(self, command: str) -> str:
        res = ""
        i = 0

        while i < len(command):
            if command[i] == 'G':
                res += 'G'
                i += 1
                continue
            elif command[i] == '(':
                if command[i + 1] == ')':
                    res += 'o'
                    i += 2
                    continue
                else:
                    res += 'al'
                    i += 4
                    continue

        return res


Solution.interpret(Solution, "G(al)()()G")
