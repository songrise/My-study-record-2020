
def main():

    infile = open("student_record.csv", "r")

    # copy the IDs to another list
    listID = []
    for record in infile:
        listID.append(record.split(",")[1])

    finalBegID = 0

    # iterate the lists from the second digit
    for begID in range(1,len(listID[1])):
        recordSet = set()
        # add the IDs into a set
        for id in range(1,len(listID)):
            recordSet.add(listID[id][begID:])

        # if there is at least one duplicate, stop
        if len(recordSet) < len(listID)-1:
            finalBegID = begID-1
            break

    # print out the compressed ID list
    for id in range(1,len(listID)):
        print(listID[id][finalBegID:])


    infile.close()
              

main()
