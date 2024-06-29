import csv
from sys import exit, argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("python dna.py data.csv sequence.txt")
        exit
    # TODO: Read database file into a variable
    else:
        csvf = open(argv[1], "r")
        textf = open(argv[2], "r")
        csvreader = csv.DictReader(csvf)
        if argv[1] == "databases/small.csv":
            iterationsize = 2
        elif argv[1] == "databases/large.csv":
            iterationsize = 7
        DNAs = []
        for row in csvreader:
            DNAs.append(row)
        # TODO: Read DNA sequence file into a variable
        text = textf.read()
        # TODO: Find longest match of each STR in DNA sequence
        matches = {}
        for keys in DNAs[0]:
            if keys == "name":
                continue
            matches[keys] = longest_match(text, keys)
        # TODO: Check database for matching profiles
        found = False
        for row in DNAs:
            name = row['name']
            counter = 0
            for STR in row:
                if STR == 'name':
                    continue
                if counter == iterationsize and int(row[STR]) == matches[STR]:
                    print(row['name'])
                    found = True
                elif int(row[STR]) != matches[STR]:
                    break
                else:
                    counter += 1
        if found == False:
            print("No match")
        csvf.close()
        textf.close()
        return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
