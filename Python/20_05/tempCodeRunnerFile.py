with open("C:\\Users\\11385\Documents\\GitHub\\My-study-record-2020\\Python\\20_05\\2020-05-25-Terminologies.md", "r+", encoding="UTF-8") as text:
    line = text.readlines()
    line += "  "
    text.writelines(line)
