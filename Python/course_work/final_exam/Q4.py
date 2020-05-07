# (a)
def flip(M, d):
    """
    A function to flip a magic square M in direction d (d is either vert or hori)
    Input: magic square M, direction d
    Output: return flipped magic square
   """
    fir = M[0]
    sec = M[1]
    trd = M[2]
    if d == 'hori':
        return [trd, sec, fir]
    elif d == 'vert':
        return[fir[::-1], sec[::-1], trd[::-1]]

# (b)


def rotate(M, d, n):
    """
    A function to rotate a magic square M in direction d (d is either clock or counter) for n
    times
    Input: magic square M, direction d, times n
    Output: return rotated magic square
    """
    if n == 0:
        return M
    else:
        fir = M[0]
        sec = M[1]
        trd = M[2]
        if d == 'clock':
            new_fir = [trd[0], sec[0], fir[0]]
            new_sec = [trd[1], sec[1], fir[1]]
            new_trd = [trd[2], sec[2], fir[2]]
            new = [new_fir, new_sec, new_trd]

            return rotate(new, d, n-1)

        elif d == 'counter':
            new_fir = [fir[2], sec[2], trd[2]]
            new_sec = [fir[1], sec[1], trd[1]]
            new_trd = [fir[0], sec[0], trd[0]]
            new = [new_fir, new_sec, new_trd]

            return rotate(new, d, n-1)

# (c)


def generate(M):
    """
    A function to return all the equivalent magic squares to M, including M
    Input: magic square M
    Output: return the list of equivalent magic squares
   """
    ans = []
    ans.append(M)
    ans.append(flip(M, 'vert'))
    ans.append(flip(M, 'hori'))
    ans.append(flip(rotate(M, 'clock', 1), 'hori'))
    ans.append(flip(rotate(M, 'clock', 1), 'vert'))

    for i in range(1, 4):
        ans.append(rotate(M, 'clock', i))

    return ans

# (d)


def before(M1, M2):
    """
    A function to determine whether M1 is before M2 in standard order
    Input: magic squares M1 and M2
    Output: return True if M1 is before M2, False otherwise
    """
    M1 = M1[0]+M1[1]+M1[2]
    M2 = M2[0]+M2[1]+M2[2]
    T = True
    for i in range(9):
        if M1[i] < M2[i]:
            return True
        elif M1[i] > M2[i]:
            break
    return False


def sortAll(M):

    allM = generate(M)
    sortedM = list()
    while allM:
        small, where = allM[0], 0
        for i in range(1, len(allM)):
            if before(allM[i], small):
                small, where = allM[i], i
        sortedM.append(small)
        del(allM[where])
    return sortedM


M = [[6, 1, 8], [7, 5, 3], [2, 9, 4]]
print("Part a")
print("Given", M)
N = flip(M, 'hori')
print("Flip horizontal", N)
N = flip(M, 'vert')
print("Flip vertical", N)
print("Rotate clockwise once", N)
N = rotate(M, 'counter', 1)
print("Rotate counter-clockwise once", N)
N = rotate(M, 'clock', 2)
print("Rotate clockwise twice", N)
N = rotate(M, 'counter', 2)
print("Rotate counter-clockwise twice", N)
N = rotate(M, 'clock', 3)
print("Rotate clockwise thrice", N)
N = rotate(M, 'counter', 3)
print("Rotate counter-clockwise thrice", N)
print("==========")
print("Part b")
allM = generate(M)
print("Equivalent magic squares to", M)
for m in allM:
    print(m)
print("==========")
print("Part c")
allM = generate(M)
sortedM = sortAll(M)
print("Sorted magic squares to", M)
for m in sortedM:
    print(m)
# print("==========")
# print("Part d")
# P = [[6,16,8],[12,10,8],[12,4,14]]
# answer = decompose(P)
# print("There are",len(answer),"answers")
# for a in answer:
#  print(P,"=",a[0],"+",a[1])
