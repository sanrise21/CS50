from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break
for i in range(0, n, 1):
    for j in range(1, n - i, 1):
        print(" ", end="")
    for k in range(1, i + 2, 1):
        print("#", end="")
    print()