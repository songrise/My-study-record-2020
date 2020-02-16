
def recordDict(fileName):
    infile = open(fileName, "r")
        
    records = dict()
    # names, IDs, Exam, Labs, Assignments
    headingNum = [1,1,1,0,0]
    firstLine = True
    for line in infile:
        if firstLine:
            headings = line[:-1].split(",")
            for item in headings:
                if "Lab" in item:
                    headingNum[3]+= 1
                elif "A" in item:
                    headingNum[4]+=1
            #print(headingNum)
            firstLine = False
        else:
            aRecord = line[:-1].split(",")
            offset = headingNum[0]+headingNum[1]
            
            # create a record for the exam mark
            examRecords = dict()
            for i in range(offset,offset+headingNum[2]):
                examRecords[headings[i]] = aRecord[i]
                
            # create records for the lab marks
            labRecords = dict()
            offset += headingNum[2]
            for i in range(offset,offset+headingNum[3]):
                tempList = []
                # create a list for the lab marks
                for j in range(offset,offset+headingNum[3]):
                    tempList.append(aRecord[j])
                # create a record for the lab marks
                labRecords[headings[i][:-1]] = tempList

            # create recods for the assignment marks
            assignRecords = dict()
            offset += headingNum[3]
            for i in range(offset,offset+headingNum[4]):
                tempList = []
                # create a list for the lab marks
                for j in range(offset,offset+headingNum[4]):
                    tempList.append(aRecord[j])
                # create a record for the lab marks
                assignRecords[headings[i][:-1]] = tempList

            # Form all the records for the students
            records[(aRecord[0], aRecord[1])] = [examRecords,labRecords,assignRecords]

    infile.close()
    return records     

def readDatabase(aDict,name,ID,item):
    if "exam" == item:
        try:
            print("The marks for "+item+":", aDict[(name,ID)][0]["Exam"])
        except KeyError:
            print("KeyError: The specified record is not in the database.")
    elif "lab" in item:
        #item[0] = "L"
        try:
            print("The marks for "+item+":", aDict[(name,ID)][1]["Lab"][int(item[3:])-1])
        except KeyError:
            print("KeyError: The specified record is not in the database.")
        except IndexError:
            print("IndexError: The specified N is out of range.")
    elif "assign" in item:
        #item = "A"+item[6:]
        #print(item)
        try:
            print("The marks for "+item+":", aDict[(name,ID)][2]["A"][int(item[6:])-1])
        except KeyError:
            print("KeyError: The specified record is not in the database.")
        except IndexError:
            print("IndexError: The specified N is out of range.")
    else:
        raise ValueError("ValueError: The specified assessment is not in the database.")

def main():
    nameID= input("Please enter the name and ID of the student separated by a comma: ")
    name, ID = nameID.split(",")
    #print(name,ID)
    item = input("Please enter the record item (exam, labN or assignN, where N is an integer starting from 1: ")
    #print(name, ID, item)
    theDict = recordDict("student_record.csv")
    #for key,value in theDict.items():
    #    print(key,"\t",value)
    try:
        readDatabase(theDict,name.lstrip().rstrip(),ID.lstrip(),item)
    except Exception as err_msg:
        print(err_msg)


main()
