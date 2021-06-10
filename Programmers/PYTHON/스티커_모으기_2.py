def solution(sticker):
    if len(sticker)==1: return sticker[0]
    if len(sticker)==2: return max(sticker[0], sticker[1])
    stick = [sticker[:-1], sticker[1:]]
    for i in range(2):
        for _ in range(2, len(stick[0])):
            if _ > 2:
                stick[i][_] += max(stick[i][_-2], stick[i][_-3])
            else:
                stick[i][_] += stick[i][_-2]
    return max(max(stick[0][-1], stick[0][-2]), max(stick[1][-1], stick[1][-2]))