class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        dic = {}

        for edge in edges:
            dic[edge[0]] = dic.get(edge[0], 0) + 1
            dic[edge[1]] = dic.get(edge[1], 0) + 1

        sortedDic = sorted(dic.items(), key=lambda x: x[1], reverse=True)

        if sortedDic[0][1] == len(edges):
            return sortedDic[0][0]

