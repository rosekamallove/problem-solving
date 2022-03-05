1.  Modular Airthematic:

    - Addition
    - Computers can store in 32 bit or 64 bit but not more than that.
    - % => (a + b) % m => overflow from (a + b)
    - Solving further: **(a%m + b%m) % m**

    - Multiplication
    - **(a*b)%m => ((a%m) * (b%m)) % m**

    - Subtraction
    - (a%m - b%m)%m this is wrong because -> it can be negative
    - **(a%m - b%m + m) %m** -> correct

2.  Fermat's Little theorem:

        a^m-1 = 1(mod m)

    If and only if a and m are coprimes

a % m / b %m != (a/b) %m

a/b => a \* (1 / b)
