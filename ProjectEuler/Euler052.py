# EUler052

from itertools import count
from sys import stdout

def E052():
    for _ in count(start=10):
        digits = sorted(str(2 * _))
        print(digits)
        if all(sorted(str(_ * k)) == digits for k in range(6, 2, -1)):
            return _

if __name__ == "__main__":
    stdout.write(str(E052()) + '\n')
