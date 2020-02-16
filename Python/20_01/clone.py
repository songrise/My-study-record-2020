# import write
with open("20_01\\test.txt", "r") as infile:
    with open("20_01\\cloned.txt", 'a') as output:
        content = infile.read()
        output.write(content)
# io mode https://www.runoob.com/python/python-files-io.html

# write.main()
