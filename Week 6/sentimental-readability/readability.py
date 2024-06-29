def Coleman(sen):
    # initializing variables outside the loop
    letter = 0
    word = 0
    sentence = 0

    # iterating through the string
    for i in range(len(sen)):
        # if its a-z or A-Z increment letter
        asci = ord(sen[i])
        if (64 < asci and asci < 91) or (96 < asci and asci < 123):
            letter += 1
        # if its . or ! or ? increment sentence
        elif asci == 46 or asci == 33 or asci == 63:
            sentence += 1
        # if its space increment the word count
        elif asci == 32:
            word += 1
    # calculating the index
    word += 1
    L = letter / word * 100;
    S = sentence / word * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index)


# Get string input from user
sentence = input("Text: ")
# Grade is the return of the function
grade = Coleman(sentence)
# if its lower than 1 its before grade 1
if grade < 1:
    print("Before Grade 1")
# if its 16 or higer its Grade 16+
elif grade >= 16:
    print("Grade 16+")
# else its that grade
else:
    print(f"Grade {grade}")