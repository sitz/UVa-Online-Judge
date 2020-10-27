import sys
from math import sqrt

for line in sys.stdin:
    T = int(line)

    diagonal_index = round(sqrt(2 * T))
    position_in_diagonal = T - (diagonal_index * (diagonal_index - 1)) // 2

    numerator = position_in_diagonal
    denominator = diagonal_index - position_in_diagonal + 1

    if diagonal_index % 2:
        numerator, denominator = denominator, numerator

    print('TERM {} IS {}/{}'.format(T, numerator, denominator))
