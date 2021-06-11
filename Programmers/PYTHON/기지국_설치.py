def solution(n, stations, w):
    answer = 0
    end = 0 
    ran = w * 2 + 1
    for _ in stations:
        if _ - w > end + 1:
            tmp = _ - w - end - 1
            answer += tmp // ran
            if tmp % ran > 0:
                answer += 1
        end = _ + w
    n -= stations[-1] + w
    if n > 0:
        answer += n // ran
        if n % ran > 0:
            answer += 1
    return answer