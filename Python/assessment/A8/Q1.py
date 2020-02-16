def getStudentInfo(sfilename):
    student = dict()
    sfile = open(sfilename, "r")
    for line in sfile.readlines():
        sinfo = line.split()
        if len(sinfo) > 0:  # skip empty lines, just in case
            sid = sinfo[0]
            sname = " ".join(sinfo[1:])  # remaining parts form the student name
            syear = int(sid[0:2])+2000
            student[sid] = [sname,syear,list()]
    return student

def getSubjectInfo(jfilename):
    subject = dict()
    jfile = open(jfilename, "r")
    for line in jfile.readlines():
        jinfo = line.split()
        if len(jinfo) > 0:  # skip empty lines, just in case
            code = jinfo[0]
            credit = int(jinfo[1])
            name = " ".join(jinfo[2:])  # remaining parts form the subject name
            subject[code] = (credit,name)
    return subject

def getStudentRecord(rfilename):
    record = dict()
    rfile = open(rfilename, "r")
    for line in rfile.readlines():
        rinfo = line.split()
        if len(rinfo) > 0:  # skip empty lines, need to do
            sid = rinfo[0]
            subj = rinfo[1]
            grade = rinfo[2]
            if sid in record:
                record[sid].append((subj,grade))
            else:
                record[sid] = [(subj,grade)]
    return record

def getGPA(subject,arecord):
    GPdict = {"A+":4.5,"A":4,"B+":3.5,"B":3,"C+":2.5,"C":2,"D+":1.5,"D":1,"F":0}
    recentGrade = dict()
    for entry in arecord:
        recentGrade[entry[0]] = entry[1] # this ensures last grade to persist
    GP, totalCR = 0, 0
    for s in recentGrade.keys():
        gr = recentGrade[s]
        cr = subject[s][0]
        totalCR = totalCR + cr
        GP = GP + GPdict[gr]*cr
    return GP / totalCR

def printTrans(student,record,subject,sid):
    subj = set()
    print("ID:",sid)
    print("Name:",student[sid][0])
#    print("Year:",student[sid][1])
    print("Subject  Title                                             Grade Cr Remark")
    for entry in record[sid]:
        if entry[0] in subj:    # second time taking or beyond
            remark = "Retake"
        else:
            subj.add(entry[0])
            remark = ""
        print("{0:9}{1:50}{2:6}{3:2} {4:6}".format(entry[0],
            subject[entry[0]][1],entry[1],subject[entry[0]][0],remark))
    GPA = getGPA(subject,record[sid])
    if GPA > 4:     # GPA capped at 4.0, do it here or inside getGPA
        GPA = 4
    print("GPA = {0:4.2f}".format(GPA))

def printCohort(student,record,subject,year):
    print("Printing cohort",year)
    for s in sorted(student.keys()):
        if student[s][1] == year:
            printTrans(student,record,subject,s)
            
students = getStudentInfo("studentInfo.txt")
subjects = getSubjectInfo("subjectInfo.txt")
records = getStudentRecord("studentRecord.txt")
for s in sorted(students.keys()):   # this prints a list sorted in id
    printTrans(students,records,subjects,s)
year = 2019
printCohort(students,records,subjects,year)
