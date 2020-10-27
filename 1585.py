import sys

T = int(sys.stdin.readline())
for t in range(T):
    test_results = sys.stdin.readline().strip()

    score = sum((len(test_result) * (len(test_result) + 1)) for test_result in test_results.split('X')) // 2

    print(score)
