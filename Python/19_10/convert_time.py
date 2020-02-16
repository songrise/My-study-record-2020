def convert():
    MonthName = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
    while True:
        a = input("please input mm/dd/yyyy:",)
        b = a.split("/")  #separtor
        index = (int(b[0]) + 1)
        print("{} {},{}".format(MonthName[index], b[0], b[2]))

convert()

        
