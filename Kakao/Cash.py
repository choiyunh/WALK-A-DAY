def solution(cacheSize, cities):
    answer = 0
    queue = []

    if cacheSize == 0:
        return len(cities) * 5
    for city in cities:
        city = city.lower()
        if city in queue:
            answer += 1
            queue.remove(city)
        else:
            answer += 5
        if queue and len(queue) == cacheSize:
            del queue[0]
        queue.append(city)

    return answer


print(solution(5,
               ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork",
                "Rome"]))
