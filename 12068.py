import sys
from fractions import Fraction, gcd

S = int(sys.stdin.readline())

for case in range(S):
    number_line = list(map(int, sys.stdin.readline().split()))

    numerator = Fraction(number_line[0])
    denominator = Fraction(0)
    for number_i in number_line[1:]:
        denominator += Fraction(numerator=1, denominator=number_i)

    fraction = numerator / denominator

    print('Case {}: {}/{}'.format(case + 1, fraction.numerator, fraction.denominator))
