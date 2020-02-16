#Q4

def remove_punc(inStr):

     listStr = []
     for char in inStr:
          if char.isalpha() == False and char != "-" and char != " ":
               listStr += ""
          else:
               listStr += char

     return "".join(listStr)

def word_length(fileName, letter):
     wordLength = 30 * [0]
     infile = open(fileName)
     for line in infile:
          aline = remove_punc(line)
          for word in aline.split():
               if word[0].lower() == letter.lower():
                    wordLength[len(word)] += 1

     for maxLen in range(len(wordLength)-1,0,-1):
          if wordLength[maxLen] != 0:
               break
               
     return wordLength[:maxLen+1]

def main():
     fileName = input("Please input a text file: ")
     print("\nThe statistics of the word length in", fileName, "are: \n")
     
     for letter in range(26):     
          length = word_length(fileName, chr(letter+97))
               
          total = 0     
          for i in range(len(length)):
               total += length[i]

          if total > 0:
               print("\nFor letter", chr(letter+97)+":")
               print("{0:<8}{1:<18}{2:<15}".format("Length", "Freq. in number", "Freq. in %"))
               for i in range(1,len(length)):
                    print("{0:<8}{1:<18}{2:<15.4f}".format(i, length[i],length[i]*100/total))
         

main()

