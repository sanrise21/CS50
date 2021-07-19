from cs50 import get_int

sumf = 0
sum1 = 0
sum2 = 0
num = get_int("Number:")
#num = int(nuum)
while True:
    if num > 0:
        break
cn = num
cn1 = num
count = 0
print()
count = count + 1
cn = int(cn / 10)
while (cn != 0):
    count = count + 1
    cn = int(cn / 10)
if count != 13 and count != 15 and count != 16:
    print("INVALID")
    exit()
for i in range(0, int(count/2), 1):
    rem = int(num % 10)
    sum1 = int(sum1 + rem)
    num = int(num / 10)
    ld = int(num % 10)
    if ld * 2 >= 10:
        sum2 = int(sum2 + ((ld * 2) / 10) + ((ld * 2) % 10))
    else:
        sum2 = int(sum2 + ld * 2)
    num = int(num / 10)
sumf = int(sum1 + sum2 + num)
if sumf % 10 == 0:
    if count == 15:
        first = int(cn1 / pow(10, 13))
        if first == 34 or first == 37:
            print("AMEX")
        else:
            print("INVALID")
    elif count == 16:
        first = int(cn1 / pow(10, 14))
        FIRST = int(cn1 / pow(10, 15))
        if first == 51 or first == 52 or first == 53 or first == 54 or first == 55:
            print("MASTERCARD")
        elif FIRST == 4:
            print("VISA")
        else:
            print("INVALID")
    elif count == 13:
        first = int(cn1 / pow(10, 12))
        if first == 4:
            print("VISA")
        else:
            print("INVALID")
else:
    print("INVALID")