def solution(files):
    answer = []
    head = []
    body = []
    allList = []
    for _ in range(len(files)):
        i = 0
        while (not (files[_][i]>='0' and files[_][i]<='9')):
            i+=1
        tmp = files[_][:i]
        head.append(tmp.lower())
        j = i
        while (j < i+5 and j < len(files[_]) and files[_][j]>='0' and files[_][j]<='9'):
            j+=1
        body.append(int(files[_][i:j]))
        allList.append({'Index':_, 'head':head[_], 'body':body[_]})
    allList = sorted(allList, key = lambda x:(x['head'],x['body']))
    for _ in allList:
        answer.append(files[_['Index']])
    return answer