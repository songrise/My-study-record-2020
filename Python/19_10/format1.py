# https://docs.python.org/3/library/string.html#string-formatting

print("first={}, second={}, third={}".format('a', 'b', 'c'))

print("first={2}, second={0}, third={1}"
      .format('a', 'b', 'c'))
L = ['aB', 'bSAD', 'cS']
print("first={}, second={}, third={}".format(*L))
# ↑unpacking sequence(iterable) using *
# L can be a string directly

print("first={fst}, second={scd}, third={trd}"
      .format(fst='a', scd='b', trd='c'))
# we cannot using both posi or key,otherwise will
# SyntaxError: positional argument follows keyword argument

print("--------ALIGNING---------")
print('[{:<30}]'.format("left alig with 30blgs"))
print("[{:^30}]".format('centered'))
print('[{:*^30}]'.format('centered'))
# use '*' as a fill char

print("{:-^24}".format("sign"))
print("{:+f}; {:+f}'".format(3.14, -3.14))

print("{:-^24}".format("conversion"))
print("int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}".format(42))
# with 0x, 0o, or 0b as prefix:
print("int: {0:d}; hex: {0:#x}; oct: {0:#o}; bin: {0:#b}".format(42))

# Using the comma as a thousands separator:
print('{:,}'.format(1234567890))
# Expressing a percentage:
print('Correct answers: {:.2%}'.format(19/22))

print('{:#^30}'.format('examples'))
for align, text in zip('<^>', ['left', 'center', 'right']):
    '{0:{fill}{align}16}'.format(text, fill=align, align=align)


octets = [192, 168, 0, 1]
print('{:02X}{:02X}{:02X}{:02X}'.format(*octets))

width = 5
for num in range(5, 12):
    for base in 'dXob':
        print('{0:{width}{base}}'.format(num, base=base, width=width), end=' ')
    print()
