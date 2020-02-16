a = "dsfaef sadffeHIUh -"
for l in a:
    if l.islower():
        a = a.replace(l, l.upper())


print(a)
