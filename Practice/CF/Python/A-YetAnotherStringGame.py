def testCase():
    s = input()
    for i in range(0, len(s)):
        if(i == 0 or i % 2 == 0):
            if(s[i] == "a"):
                b_s = bytearray(s)
                b_s[i] = "b"
                s = str(b_s)
            else:
                b_s = bytearray(s)
                b_s[i] = "a"
                s = str(b_s)
        else:
            if(s[i] == "z"):
                b_s = bytearray(s)
                b_s[i] = "y"
                s = str(b_s)
            else:
                b_s = bytearray(s)
                b_s[i] = "y"
                s = str(b_s)
    print(s)


def solution():
    for i in range(int(input())):
        testCase()


solution()
