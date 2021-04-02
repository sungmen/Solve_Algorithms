def solution(m, musicinfos):
    answer = ''
    cmpArr = []
    i = 0
    while(i < len(m)):
        if i + 1 < len(m) and m[i+1] == '#':
            cmpArr.append(m[i]+m[i+1])
            i += 2
        else:
            cmpArr.append(m[i])
            i += 1
    cmpStr = ''
    for _ in cmpArr:
        cmpStr += (_ + ',')
    maxTime = 0
    for _ in musicinfos:
        arr = _.split(',')
        time = int(arr[1][0:2])*60+int(arr[1][3:5])-(int(arr[0][0:2])*60+int(arr[0][3:5]))
        tmpArr = []
        tmpP = arr[3].split(',')
        i = 0
        while(i < len(arr[3])):
            if i + 1 < len(arr[3]) and arr[3][i+1] == '#':
                tmpArr.append(arr[3][i]+arr[3][i+1])
                i += 2
            else:
                tmpArr.append(arr[3][i])
                i += 1
        myStr = ''
        for i in range(time):
            myStr += (tmpArr[i%len(tmpArr)]+',')
        if cmpStr in myStr and maxTime < time:
            answer = arr[2]
            maxTime = time
    return answer if answer!='' else '(None)'