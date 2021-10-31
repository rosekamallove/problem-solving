# -- Prime ------------------------------------------------------------------
primeLimit = int(5*1e4)
prime = [True for i in range(primeLimit+1)]
primeNums = []


def pre():
    p = 2
    while(p*p <= primeLimit):
        if(prime[p] == True):
            for i in range(p*2, primeLimit, p):
                prime[i] = False
        p += 1
    prime[0] = False
    prime[1] = False
    for i in range(2, primeLimit):
        if(prime[i] == True):
            pr = int(i)
            primeNums.append(pr)


def gcd(x, y):
    while(y):
        x, y = y, x % y
    return x


def testCase():
    a, b, k = map(int, input().split())
    mxSteps = 0
    mnSteps = 0

    # -- Counting Minimum Steps ---------------------------------------------
    if(a == b):
        mnSteps = 0
    elif(gcd(a, b) == a or gcd(a, b) == b):
        mnSteps = 1
    else:
        mnSteps = 2

    # -- Counting MaxStpes --------------------------------------------------
    # For a:
    for x in primeNums:
        if(x * x > a):
            break
        while(a % x == 0):
            mxSteps = mxSteps + 1
            a = a/x
    if(a > 1):
        mxSteps = mxSteps + 1

    # For b:
    for x in primeNums:
        if(x * x > b):
            break
        while(b % x == 0):
            mxSteps = mxSteps + 1
            b = b/x
    if(b > 1):
        mxSteps = mxSteps + 1
    # -------------------------------------------------------------------------

    if(k >= mnSteps and k <= mxSteps and k == 1 and mnSteps == 1):
        print("YES")
        return
    if(k >= mnSteps and k <= mxSteps and k != 1):
        print("YES")
        return
    print("NO")


# --------------------------------------------------------------------------------------

def solution():
    pre()
    for _ in range(int(input())):
        testCase()


solution()
