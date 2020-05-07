def harry(s: str, t: str):
    """Compare two strings.
       Print True if s and t satisfy Harry Potter Transformation, else print false and print different letters respectively. 
       s and t are two str, consisting only of lower case letters and blanck space. 
    """
    n = 0  # Varible n represents repeating times for a letter, which will be specified in for loop.
    identical = True

    print('Checking "{}" with "{}":'.format(s, t), end='')
    for letter in range(ord("a"), ord("z")+1):  # Blank space will not be counted
        # Avoid unnecessary calculation.
        if chr(letter) not in s and chr(letter) not in t:
            continue
        for S_letter in s:
            # Count repeating times of "the letter" in s.
            if ord(S_letter) == letter:
                n += 1
        for T_letter in t:
            if ord(T_letter) == letter:
                n -= 1  # Calculate the difference
        if n != 0:  # Judge whether the "letter" have same repeating times in two string.
            if identical:  # Print and only print "False" once.
                print("False")
            identical = False
        else:
            continue
        print("Too {} {}".format("few" if n < 0 else "many", chr(letter)))
        n = 0
    if identical:  # Only if n always euqal to 0 in 26 iterations, which is the sufficient and necessary condition of the Harry Potter Transformation
        print("True")


# Test
harry("tom marvolo riddle", "i am lord voldemort")
harry("harry potter", "my hero part")
harry("a computer", "our pet mac")
