# BOJ10828.py
# RUN pypy3 BOJ10828.py
from sys import stdin
from sys import stdout

class Stack(list):
    push = list.append

    def is_empty(self):
        if not self:
            return True
        else:
            return False

    def is_pop(self):
        if self.is_empty():
            return -1
        return self.pop()

    def is_size(self):
        return len(self)

    def top(self):
        if self.is_empty():
            return -1
        return self[-1]

if __name__ == "__main__":
    stack = Stack()
    for _ in range(int(input())):
        sta = stdin.readline().split()
        if sta[0] == "push":
            stack.push(str(sta[1]))
        elif sta[0] == "pop":
            stdout.write(str(stack.is_pop()) + '\n')
        elif sta[0] == "size":
            stdout.write(str(stack.is_size()) + '\n')
        elif sta[0] == "empty":
            if stack.is_empty():
                stdout.write(str(1) + '\n')
            else:
                stdout.write(str(0) + '\n')
        elif sta[0] == "top":
            stdout.write(str(stack.top()) + '\n')
