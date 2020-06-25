def zeroPad(numberString, zeros, right = False):
    '''Returning strings with zeros added to the right or left.'''

    for i in range(zeros):
        if (right):
            numberString = numberString + '0'
        else:
            numberString = '0' + numberString

    return numberString

def karatsubaMultiplication(x, y):
    '''Multiplying two integers using Karatsuba Algorithm.'''

    # For easier access to digits, integers converted to strings.
    x = str(x)
    y = str(y)

    # Base case for this recursive algorithm.
    if ((len(x) == 1) or (len(y) == 1)):
        return int(x)*int(y)

    # Make sure the length of x and y is same by adding left padding with zeros if required.
    if (len(x) < len(y)):
        x = zeroPad(x, len(y)-len(x), False)
    elif (len(y) < len(x)):
        y = zeroPad(y, len(x)-len(y), False)


    n = len(x)
    k = n//2

    #In case of odd digit integers
    if ((n%2) != 0):
        k += 1

    BzeroPadding  = n - k
    AzeroPadding = BzeroPadding * 2


    # # Alter if length of x and y is odd.
    #
    # # If the length of x and y is not even, add one zero using left padding.
    # if (len(x)%2 != 0):
    #     x = zeroPad(x,1)
    #     y = zeroPad(y,1)
    #
    # n = len(x)
    # k = n//2
    #
    # BzeroPadding = int(k)
    # AzeroPadding = int(n)

    a = int(x[:k])
    b = int(x[k:])
    c = int(y[:k])
    d = int(y[k:])

    # Recursive calculation.

    ac = karatsubaMultiplication(a, c)
    bd = karatsubaMultiplication(b, d)
    p = karatsubaMultiplication(a+b, c+d)

    A = zeroPad(str(ac), AzeroPadding, True)
    B = zeroPad(str(p - ac - bd), BzeroPadding, True)

    return int(A) + int(B) + int(bd)

X ,Y = input('Enter two numbers to be multiplied: ').split(' ')
ans = karatsubaMultiplication(X, Y)
print(ans)
