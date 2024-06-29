import sys
def quarters(change):
    counter = 0
    while change >= 0.25:
        change -= 0.25
        counter += 1
    return change, counter
def dimes(change):
    counter = 0
    while change >= 0.10:
        change -= 0.10
        counter += 1
    return round(change, 2), counter
def nickels(change):
    counter = 0
    while change >= 0.05:
        change -= 0.05
        counter += 1
    return round(change, 2), counter
def pennies(change):
    counter = 0
    while change >= 0.01:
        change -= 0.01
        counter += 1
    return round(change, 2), counter
coins = 0
while True:
    try:
        change = float(input("Change owed: "))
        if change > 0:
            break
    except:
        sys.exit
change, coins_increment = quarters(change)
coins += coins_increment
change, coins_increment = dimes(change)
coins += coins_increment
change, coins_increment = nickels(change)
coins += coins_increment
change, coins_increment = pennies(change)
coins += coins_increment

print(coins)