def solution(rows, columns, queries):
    answer = []
    arr = [[j for j in range (i, i + columns)] for i in range(1, columns*rows, columns)]
    for _ in queries:
        y1, x1, y2, x2 = _[0]-1, _[1]-1, _[2]-1, _[3]-1
        small = 100000009
        tmp = arr[y1][x1]
        if(tmp < small):
            small = tmp
        for i in range(x1, x2):
            tmp2 = arr[y1][i+1]
            arr[y1][i+1] = tmp
            tmp = tmp2
            if tmp2 < small:
                small = tmp2
        if tmp < small:
            small = tmp
        for i in range(y1, y2):
            tmp2 = arr[i+1][x2]
            arr[i+1][x2] = tmp
            tmp = tmp2
            if tmp2 < small:
                small = tmp2
        for i in range(x2, x1, -1):
            tmp2 = arr[y2][i-1]
            arr[y2][i-1] = tmp
            tmp = tmp2
            if tmp2 < small:
                small = tmp2
        for i in range(y2, y1, -1):
            tmp2 = arr[i-1][x1]
            arr[i-1][x1] = tmp
            tmp = tmp2
            if tmp2 < small:
                small = tmp2
        answer.append(small)
        
        
    return answer