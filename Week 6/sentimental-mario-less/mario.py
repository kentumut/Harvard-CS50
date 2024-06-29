while True:
    try:
        n = int(input("Height : "))
    except:
        continue
    if n > 0 and n <= 8:
        break

for i in range(n):
    print(" " * (n - i - 1), end="")
    print("#" * (i + 1))