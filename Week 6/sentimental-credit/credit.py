import sys


# Function checking the credit card with the checksum
def validator(ccnumber):
    creditcard = ccnumber
    # Geting every other digit starting with the last
    sum1 = 0
    while creditcard > 0:
        last_digit = creditcard % 10
        sum1 += last_digit
        creditcard = creditcard // 100
    # Getting every other digit starting with the second last
    sum2 = 0
    creditcard = ccnumber // 10
    while creditcard > 0:
        last_digit = creditcard % 10
        sum2 += (2 * last_digit % 10) + (2 * last_digit) // 10
        creditcard = creditcard // 100
    # If the total of the sums modulo 10 is congruent to 0 the cards are valid
    fsum = sum1 + sum2
    if fsum % 10 == 0:
        return True
    else:
        return False


# Function saying the name of the provider
def company(ccnumber):
    # Trying to find the credit card length
    length = 0
    while ccnumber > 100:
        ccnumber = ccnumber // 10
        length += 1
    # Keeps first two digits of the creditcardnumber
    length += 2
    # If the creditcard number starts with 4 and its length is 13 or 16 it's VISA
    if ccnumber // 10 == 4 and (length == 13 or length == 16):
        return "VISA"
    # If the creditcard number starts with 34 or 37 and its length is 16 it's American Express
    elif (ccnumber == 34 or ccnumber == 37) and length == 15:
        return "AMEX"
    # If the creditcard number starts with 51 or 52 or 53 or 54 and its length is 16 it's Mastercard
    elif (
        ccnumber == 51
        or ccnumber == 52
        or ccnumber == 53
        or ccnumber == 54
        or ccnumber == 55
    ) and length == 16:
        return "MASTERCARD"
    else:
        return "INVALID"


# Asking user the Credit Card Number
try:
    ccnumber = int(input("Number: "))
except:
    sys.exit
# If checksum validates print which company's card it is else print invalid
if validator(ccnumber):
    print(f"{company(ccnumber)}")
else:
    print("INVALID")
