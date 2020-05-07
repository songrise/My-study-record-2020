# 2020/1/7 13min


def strToList(s: str) -> list:
    """
    Identify words in a string, the sequence is unchanged
    Input:a String
    Output:a list containing all words in the given string
    """

    wordList = []
    word = ''
    for l in s:
        if not l.isspace() and l != '.':
            word += l
        else:
            wordList.append(word)
            word = ''

    return wordList


def main():
    string = input("Please input a string:")
    word = strToList(string)
    reverseStr = " ".join(word[::-1])  # slice reverse
    if string[len(string)-1] == '.':  # maintain the full stop
        reverseStr += '.'
    print(reverseStr)


main()
