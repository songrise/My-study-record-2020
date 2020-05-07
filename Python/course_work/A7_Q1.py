def analyze(m: str):
    """analyze the frequency of every letters in a given str

    print a frequency report on the letters with deviation
    return a dictionary for decryption mapping.
    """
    m = m.casefold()
    freq = {chr(letter): 0 for letter in range(97, 123)}
    # {Letter:frequency}
    freq_table = {'e': 12.7, 't': 9.06, 'a': 8.17, 'o': 7.51, 'i': 6.97, 'n': 6.75, 's': 6.33,
                  'h': 6.09, 'r': 5.99, 'd': 4.25, 'l': 4.03, 'c': 2.78, 'u': 2.76,  'm': 2.41, 'w': 2.36,
                  'f': 2.23, 'g': 2.02, 'y': 1.97, 'p': 1.93, 'b': 1.49, 'v': 0.98, 'k': 0.77, 'j': 0.15,
                  'x': 0.15, 'q': 0.10, 'z': 0.07}
    for char in m:
        if not char.isalpha():
            m = m.replace(char, '')  # remove nonalpha chars
    for letter in m:
        freq[letter] += 1
    for alpha in range(97, 123):
        freq[chr(alpha)] = (freq[chr(alpha)]/len(m))*100

    sorted_letter = sorted(freq.items(), key=lambda x: x[1], reverse=True)
    frequency_for_decode = sorted(
        freq_table.items(), key=lambda x: x[1], reverse=True)  # sort
    # this list contains letter according to their frequecy.

    cipher = [key[0] for key in sorted_letter]
    plain = [key[0] for key in frequency_for_decode]
    map = {cipher[i]: plain[i] for i in range(26)}

    print("map          difference")
    for index in range(26):
        print("{} <- {}       {:3.2f}%".format(chr(index+97), map[chr(index+97)],
                                               abs(freq[chr(index+97)]-freq_table[map[chr(index+97)]])))

    return map


def decrypt(m: str, mapping: dict):
    """return a decrypted message for m based on the mapping"""
    m_list = list(m)  # convert str in to a mutable type
    for i in range(len(m_list)):
        if m_list[i].isalpha():
            if m_list[i].isupper():
                m_list[i] = m_list[i].lower()
                m_list[i] = mapping[m_list[i]]
                m_list[i] = m_list[i].upper()
            else:
                m_list[i] = mapping[m_list[i]]
    m = "".join(m_list)
    return m


m1 = "This text introduces students to programming and computational problem \
solving using the Python 3 programming language. \
It is intended primarily for a first-semester computer science (CS1) course, \
but is also appropriate for use in any course providing an introduction \
to computer programming and/or computational problem solving. The book \
provides a step-by-step,'hands on' pedagogical approach which, together \
with Python's clear and simple syntax, makes this book easy to teach and \
learn from."
m2 = "Ziol ztbz ofzkgrxetl lzxrtfzl zg hkgukqddofu qfr egdhxzqzogfqs hkgwstd \
lgscofu xlofu zit Hnzigf 3 hkgukqddofu sqfuxqut. \
Oz ol ofztfrtr hkodqkosn ygk q yoklz-ltdtlztk egdhxztk leotfet (EL1) egxklt, \
wxz ol qslg qhhkghkoqzt ygk xlt of qfn egxklt hkgcorofu qf ofzkgrxezogf \
zg egdhxztk hkgukqddofu qfr/gk egdhxzqzogfqs hkgwstd lgscofu. Zit wgga \
hkgcortl q lzth-wn-lzth,'iqfrl gf' htrquguoeqs qhhkgqei vioei, zgutzitk \
vozi Hnzigf'l estqk qfr lodhst lnfzqb, dqatl ziol wgga tqln zg ztqei qfr \
stqkf ykgd. \
Zit hkodqkn ugqs of zit rtctsghdtfz gy ziol ztbz vql zg ektqzt q htrquguoeqssn \
lgxfr qfr qeetllowst ztbzwgga ziqz tdhiqlomtl yxfrqdtfzqs hkgukqddofu \
qfr egdhxzqzogfqs hkgwstd-lgscofu egfethzl gctk zit dofxzoqt gy q hqkzoexsqk \
hkgukqddofu sqfuxqut. Hnzigf'l tqlt of zit ektqzogf qfr xlt gy wgzi ofrtbtr \
qfr qllgeoqzoct rqzq lzkxezxktl (of zit ygkd gy solzl/zxhstl qfr roezogfqkotl), \
Ql vtss ql ltzl, qssgvl ygk hkgukqddofu egfethzl zg wt rtdgflzkqztr vozigxz \
zit fttr ygk rtzqostr rolexllogf gy hkgukqddofu sqfuxqut lhteoyoel. \
Zqaofu qrcqfzqut gy Hnzigf'l lxhhgkz gy wgzi zit odhtkqzoct (o.t., hkgetrxkqs) \
qfr gwptezgkotfztr hqkqroudl, q 'wqea zg wqloel', 'gwptezl-sqzt' qhhkgqei \
ol zqatf zg egdhxztk hkgukqddofu. \
Oz ygssgvl zit wtsoty ziqz lgsor ukgxfrofu of odhtkqzoct hkgukqddofu \
ligxsr hktetrt zit sqkutk fxdwtk gy (qfr dgkt qwlzkqez) egfethzl gy zit \
gwptez-gkotfztr hqkqroud. Zitktygkt, gwptezl qkt fgz egctktr xfzos Eiqhztk 5, \
qfr gwptez-gkotfztr hkgukqddofu ol fgz ofzkgrxetr xfzos Eiqhztk 10. \
Ygk ziglt vig rg fgz voli zg ofzkgrxet gwptez-gkotfztr hkgukqddofu, \
Eiqhztk 10 eqf tqlosn wt laohhtr. Ziqfal."
mapping = analyze(m1)
print("Mapping dictionary:", mapping)
print("plaintext:", decrypt(m1, mapping))
print("plaintext:", decrypt(m1, {'a': 'a', 'b': 'b', 'c': 'c', 'd': 'd', 'e': 'e', 'f': 'f',
                                 'g': 'g', 'h': 'h', 'i': 'i', 'j': 'j', 'k': 'k', 'l': 'l', 'm': 'm',
                                 'n': 'n', 'o': 'o', 'p': 'p', 'q': 'q', 'r': 'r', 's': 's', 't': 't',
                                 'u': 'u', 'v': 'v', 'w': 'w', 'x': 'x', 'y': 'y', 'z': 'z'}))
mapping = analyze(m2)
print("Mapping dictionary:", mapping)
print("plaintext:", decrypt(m2, mapping))
# note first word could be "This" and single "o" should probably be "a"
# adjust the mapping based on this observation
print("plaintext:", decrypt(m2, {'e': 'd', 'l': 's', 'w': 'g', 'x': 'f', 'q': 'a',
                                 'h': 'r', 'i': 'h', 'n': 'p', 'g': 'o', 'r': 'l', 'z': 't',
                                 's': 'm', 'p': 'j', 'a': 'v', 'u': 'u', 'y': 'y', 'j': 'z',
                                 'c': 'b', 't': 'e', 'd': 'c', 'b': 'x', 'o': 'i', 'v': 'k',
                                 'f': 'w', 'm': 'q', 'k': 'n'}))
# knowing that this is about Python, "Rp*tho*w 3" might be "Py*tho*n 3"
print("plaintext:", decrypt(m2, {'e': 'd', 'l': 's', 'w': 'g', 'x': 'f', 'q': 'a',
                                 'h': 'p', 'i': 'h', 'n': 'y', 'g': 'o', 'r': 'l', 'z': 't',
                                 's': 'm', 'p': 'j', 'a': 'v', 'u': 'u', 'y': 'r', 'j': 'z',
                                 'c': 'b', 't': 'e', 'd': 'c', 'b': 'x', 'o': 'i', 'v': 'k',
                                 'f': 'n', 'm': 'q', 'k': 'w'}))
# now it should not be very hard to get the remaining ones by yourself (this is not neededin this assignment)
