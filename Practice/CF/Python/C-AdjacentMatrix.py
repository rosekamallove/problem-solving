def testCase():
    num = int(input())
    if(num == 1):
        print(1)
        return
    if(num == 2):
        print(-1)
        return

    even, odd = 2, 1

    arr = [[0]*(num + 1)]*(num + 1)
    for i in range(1, num + 1):
        for j in range(1, num + 1):
            if(i+j <= (num*num - 1)/2 and even <= num*num):
                arr[i][j] = even
                even = even + 2
            elif (odd <= num * num):
                arr[i][j] = odd
                odd += 2

    for i in range(1, num + 1):
        for j in range(1, num + 1):
            print(arr[i][j], end=" ")
        print()


def solution():
    for i in range(int(input())):
        testCase()


solution()
