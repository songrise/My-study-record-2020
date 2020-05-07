
def main():
      def factors(n):
            output = []
            for i in range(1,n//2+1):
                  if not n%i:
                        output += [i]
            output += [n]
            return output

      m = eval(input("\nPlease enter a positive number: "))
      print("The factors for", m, "are", str(factors(m))+".", "\n")
                  
main()
