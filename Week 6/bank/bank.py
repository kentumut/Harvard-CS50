greeting = input("Greeting: ")

if greeting.lower().strip()[:5] == "hello":
    print("$0")
elif greeting.lower().strip()[0] == "h":
    print("$20")
else:
    print("$100")