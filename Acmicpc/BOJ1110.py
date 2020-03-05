# BOJ1110.py

count = num = 0

def inp():
    global num
    num = int(input())

def cycle(csum):
    global count
    global num
    count += 1
    if count == 1:
        csum = num
    if num == csum and count != 1:
        return count -1
    last = csum%10
    Sum = (sum(map(int ,str(csum)))%10)
    csum = (last*10) + Sum
    return cycle(csum)
    

if __name__=="__main__":
    inp()
    print(cycle(num))
