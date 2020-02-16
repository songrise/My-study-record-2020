list=[1,2,3,4,5,6,7]
#slice[start:end:step]
print(list[0])
print(list[::2])

#dic={list:1} error, key must be immutable
dic={"l":list}
print(dic["l"])
