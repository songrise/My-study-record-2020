def genlegalStates():
    """ print legal states in MCGW problem."""
    m, c, g, w = 0, 0, 0, 0  # Actually boolean, 0 -> E and 1 -> W.
    for m in range(2):
        for c in range(2):
            for g in range(2):
                for w in range(2):
                    if m != c == g or m != g == w:  # These states are not satisfy the constraint.
                        continue
                    print("{}{}{}{}".format("W" if m else "E", "W" if c else "E",
                                            "W" if g else "E", "W" if w else "E"))  # Can be expanded but to long.
    return None


genlegalStates()
