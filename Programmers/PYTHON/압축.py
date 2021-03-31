def solution(msg):
    answer = []
    i = 0
    dic = {}
    for _ in range(1, 27):
        dic[chr(_ - 1 + ord('A'))] = _
    num = 27
    while (i < len(msg)):
        tmp = msg[i]
        i += 1
        while (i < len(msg)):
            tmp_next = tmp + msg[i]
            if tmp_next in dic.keys():
                i += 1
                tmp = tmp_next
            else:
                answer.append(dic[tmp])
                dic[tmp_next] = num
                num += 1
                break
    answer.append(dic[tmp])
    return answer