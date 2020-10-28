import sys

case = 1
for line in sys.stdin.readlines():
    [Z, I, M, L] = list(map(int, line.rstrip().split()))

    if not all([Z, I, M, L]):
        break

    random_numbers = [L % M]
    random_numbers_set = {L % M}
    while True:
        next_random_number = (Z * L + I) % M
        if next_random_number in random_numbers_set:
            print('Case {}: {}'.format(case, len(random_numbers) - random_numbers.index(next_random_number)))
            break
        else:
            random_numbers_set.add(next_random_number)
            random_numbers.append(next_random_number)
            L = next_random_number

    case += 1
