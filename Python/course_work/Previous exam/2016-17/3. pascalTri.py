def pascalTri(n):

     # compute the next row based on the current row
     def nextRow(curRow):
          newRow = [1]
          for x in range(len(curRow)-1):
               newRow.append(curRow[x] + curRow[x+1])
          return newRow+[1]
     
     # n = 0
     if n == 0:
          result = [[1]]
     # n = 1
     elif n == 1:
          result = [[1],[1,1]]
     # n > 1
     else:
          result = [[1], [1,1]]
          for x in range(n-1):
               result.append(nextRow(result[len(result)-1]))

     print("The Pascal's Triangle for", n, "levels is:")
     for row in result:
          print(row)

#pascalTri(10)

# test for n = 15 for preventing hard-coded solution
pascalTri(15)
