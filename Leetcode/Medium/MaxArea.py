class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()

        widths = [verticalCuts[0] - 0]
        for i in range(1, len(verticalCuts)):
            widths.append(verticalCuts[i] - verticalCuts[i - 1])
        widths.append(w - verticalCuts[-1])

        heights = [horizontalCuts[0] - 0]
        for i in range(1, len(horizontalCuts)):
            heights.append(horizontalCuts[i] - horizontalCuts[i - 1])
        heights.append(h - horizontalCuts[-1])

        return max(heights) * max(widths) % 1000000007
