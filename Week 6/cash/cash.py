
from cs50 import get_float


dollars = get_float("Change owed: ")
coins = 0

cents = round(dollars * 100)
while cents != 0:
    if cents >= 25:
        cents = cents - 25
        coins += 1
    elif cents >= 10:
        cents = cents - 10
        coins += 1
    elif cents >= 5:
        cents = cents - 5
        coins += 1
    elif cents >= 1:
        cents = cents - 1
        coins += 1


print(coins)