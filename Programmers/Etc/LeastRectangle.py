def solution(sizes):
    width, height = [], []
    for size in sizes:
        width.append(max(size))
        height.append(min(size))

    return max(width) * max(height)