height_weight = {"张三丰": [175.5, 50.0], "徐敏敏": [
    165.0, 53.8], "刘思宇": [185.0, 70.5], "王运运": [155.8, 60.2]}

for key in height_weight.keys():
    print("姓名：{}, 身高： {}， 体重： {}".format(
        key, height_weight[key][0],  height_weight[key][1]))


l = [3, 1, 2, 4, 5]
for index, entry in enumerate(l):
    print(index, entry)
