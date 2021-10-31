def testCase():
    num = int(input())
    if(num % 2050 != 0):
        print(-1)
        return
    cnt = 0
    num = num/2050
    while(num > 0):
        temp = num % 10
        num = num // 10
        cnt = temp + cnt
    print(int(cnt))


def solution():
    for _ in range(int(input())):
        testCase()


solution()
