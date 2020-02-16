#write in 2020/1/17


def count(f) -> dict:
    """Input : an file obj
        output: frequency table(in a dict format)
    """
    ans = {l: 0 for l in 'abcdefghijklmnopqrstuvwxyz'}
    # text processing
    txt = f.read()
    for letter in txt:
        if letter.isupper():
            txt = txt.replace(letter, letter.lower())
        if not letter.isalpha():
            txt = txt.replace(letter, '')
    # letter count
    for letter in txt:
        if letter.isalpha():
            ans[letter] += 1

    length = len(txt)
    # frequency calculate
    for k in ans.keys():
        ans[k] /= length

    return ans


def put(a: dict):
    total = 0
    for k, v in a.items():
        print("Letters: ", k, end='')
        print("Frequency: ", v)
        total += v
    print("total= ", total)


def main():
    with open("20_01\\passage.txt", "r") as f:
        ans = count(f)
        put(ans)


main()
