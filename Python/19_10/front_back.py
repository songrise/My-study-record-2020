def front_back(str):
  a = list(str)
  a[0], a[-1] = a[-1], a[0]
  str = "".join(a)
  return str

print(front_back('code'))
print(front_back('a'))
print(front_back('ab'))