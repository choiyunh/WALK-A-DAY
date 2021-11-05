class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        answer = []

        for num in nums:
            temp = [n for n in nums if n < num]
            answer.append(len(temp))

        return answer