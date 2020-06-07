def solution(participant, completion):
    participant.sort()
    completion.sort()
    l = 0
    for i in range(len(completion)):
        if participant[i] != completion[i]:
            return participant[i]
        l = i
    return participant[l+1]
    