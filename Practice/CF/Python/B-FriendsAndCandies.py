def testCase():
    size = int(input())
    arr = [int(a) for a in input().split()]

    sum = 0
    for i in arr:
        sum = sum + i

    isIt = True
    for i in arr:
        if(i*size != sum):
            isIt = False
    if(isIt):
        print(0)
        return

    if(sum % size != 0):
        print(-1)
        return

    target = sum / size
    count = 0
    for i in arr:
        if(i > target):
            count = count + 1
    print(count)


def solution():
    for i in range(int(input())):
        testCase()


solution()
