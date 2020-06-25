def zeroPad(numberString, zeros, right = False):
    '''Returning strings with zeros added to the right or left.'''

    for i in range(zeros):
        if (right):
            numberString = numberString + '0'
        else:
            numberString = '0' + numberString

    return numberString


def thirdGradeMultiplication(x, y):
    ''' Multiplying two digits using the third grade multiplication algorithm. '''

    # For easier access to digits, integers converted to strings.
    x = str(x)
    y = str(y)

    # Keeping track of the number of zeros required to pad partial multiplications.
    zeroPadding = 0

    # Sum of partial multiplications as we go.
    partialSum = 0

    # Looping over each digit in second number.
    for i in range(len(y)-1, -1, -1):

        # Keeping track of carry for multiplications resulting in answers > 9
        carry = 0

        # Partial nultiplications answer for string for easier manipulations.
        partial = ''

        z = 0

        # Adding padding with zeros on the right.
        partial = zeroPad(partial, zeroPadding, True)

        # Looping over each digit in the first number.
        for j in range(len(x)-1, -1 , -1):
            z = int(x[j]) * int(y[i])
            z = z + carry

            # Converting to string for easier manipulation
            w = str(z)

            # Keeping track of carry for answers > 9
            if (len(w)>1):
                carry = int(w[0])
            else:
                carry = 0

            # Concatenate the final answer to the left of the partial string
            partial = w[len(w)-1] + partial

        # In case carry is left at the end, concatenate it to partial string.
        if (carry>0):
            partial =  str(carry) + partial

        # Summing partials as we go
        partialSum += int(partial)

        # For the next digit of the second number, pad another zero to the right.
        zeroPadding += 1

    return partialSum

X ,Y = input('Enter two numbers to be multiplied: ').split(' ')
ans = thirdGradeMultiplication(X, Y)
print(ans)
