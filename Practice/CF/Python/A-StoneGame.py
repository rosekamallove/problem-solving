
def testCase():
    size = int(input())
    arr = [int(el) for el in input().split()]

    idx1 = 0
    idx2 = 0
    for i in range(0, size):
        if(arr[i] < arr[idx1]):
            idx1 = i
        if(arr[i] > arr[idx2]):
            idx2 = i

    minl = min(idx1, idx2)
    maxl = max(idx1, idx2)
    a1 = size - minl
    a2 = maxl + 1
    a3 = minl + 1 + size - maxl
    print(min(a1, a2, a3))


def solution():
    for i in range(int(input())):
        testCase()


solution()
