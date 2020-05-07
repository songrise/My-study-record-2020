def main():

     def getSentences(infile):
          """ This function accepts a file handler of a text file and returns the sentences in the file as a list."""
          sList = []
          sentence = []

          for line in infile:
               linesplit = line.split()
               for word in linesplit:
                    sentence.append(word)
                    if ("." in word and word[len(word)-1] == ".") or ("?" in word and word[len(word)-1] == "?"):
                         sList.append(sentence)
                         sentence = []

          return sList


     def analyzeSentences(aList):
          """ This function accepts a list of sentences and prints out the statistics of the sentence length. """
          length = {}
          for i in aList:
               if len(i) in length:
                    length[len(i)] += 1
               else:
                    length[len(i)] = 1

          value_key_list = []
          for key, val in length.items():
               value_key_list.append((key, val))

          total_count = 0
          for val in length.values():
               total_count += val
          
          sorted_value_key_list = sorted(value_key_list)

          print("\n{0:^25}{1:^25}{2:^25}".format("Length of sentence", "Frequency in counts", "Frequency in %"))
          for key, val in sorted_value_key_list:
               print("{:^25d}{:^25d}{:^25.2f}".format(key, val, val*100/total_count))


     fileName = input("Please input a text file: ")
     infile = open(fileName)
     sList = getSentences(infile)
     for i in sList:
          print(i)
     analyzeSentences(sList)


main()
