class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        count = 0
        rule = {'type': 0, 'color': 1, 'name': 2}

        for item in items:
            if ruleValue == item[rule[ruleKey]]:
                count += 1
                continue

        return count
