from pyfiglet import Figlet
from sys import argv, exit
from random import randrange
f = Figlet()
argc = len(argv) - 1
if argc == 0:
    list = f.getFonts()
    f.setFont(font= list[randrange(50)])
    text = input("Input: ")
    print("Output:\n" + f.renderText(text))
elif argc == 2 and (argv[1] == "-f" or argv[1] == "--font"):
    f.setFont(font=argv[2])
    text = input("Input: ")
    print("Output:\n" + f.renderText(text))
else:
    print("Invalid usage")
    exit(1)