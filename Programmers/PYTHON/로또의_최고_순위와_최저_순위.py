def solution(lottos, win_nums):
    answer = [0, 0]
    zero = lottos.count(0)
    mapp = {}
    for _ in win_nums:
        mapp[_] = 1
    cnt = 0
    for _ in lottos:
        if _ in mapp.keys():
            cnt += 1
    first = zero + cnt
    answer[0] = 7 - first
    if (answer[0] > 5):
        answer[0] = 6
    answer[1] = 7 - cnt
    if (answer[1] > 5):
        answer[1] = 6
    return answer