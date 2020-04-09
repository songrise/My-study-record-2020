# arr = eval(input())

# temp = (input()).split(",")
# first, end = int(temp[0]), int(temp[1])

# print(arr[first:end])

# length = len(students)
# i = 0
# while i < length:
#     print(students[i], '  ', students[i+1], '\n')
#     i += 2

students = ['李运江', 90, '李俊', '98', '王林', 78, '王德仁', 88]

for i in range(len(students)//2):
    print(students[2*i], '  ', students[2*i+1], '\n')
