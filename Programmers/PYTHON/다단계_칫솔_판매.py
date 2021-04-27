def solution(enroll, referral, seller, amount):
    answer = []
    name = {}
    money = {}
    for _ in range(len(enroll)):
        name[enroll[_]] = referral[_]
        money[enroll[_]] = 0
    for _ in range (len(amount)):
        amount[_] *= 100
    for _ in range (len(seller)):
        str = ""
        tmp = amount[_] - int(amount[_]/10)
        tmp_n = int(amount[_]/10)
        money[seller[_]] += tmp
        str = name[seller[_]]
        mm = tmp_n
        while(str != "-"):
            tmp_n = int(mm / 10)
            tmp = mm - int(mm / 10)
            money[str] += tmp
            str = name[str]
            mm = tmp_n
    for _ in enroll:
        answer.append(money[_])
    return answer