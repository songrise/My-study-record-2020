with open("C:\\Users\\11385\Documents\\GitHub\\My-study-record-2020\\Python\\20_05\\2020-05-25-Terminologies.md", "r+", encoding="UTF-8") as i:
    with open("C:\\Users\\11385\Documents\\GitHub\\My-study-record-2020\\Python\\20_05\\output.md", "r+", encoding="UTF-8") as o:
        while True:
            line = i.readline()
            if not line:
                break
            end = line.index('\n')
            line = line[:end]+"  "+line[end:]

            o.writelines(line)
