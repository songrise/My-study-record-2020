#Q7

def gcd(a, b):
     while a % b != 0:
          a, b = b, a % b
     return b

def lcm(a, b):
     return (a*b)//gcd(a,b)


class Rational(object):
     def __init__(self, numer, denom=1, whole=0):
          ''' Rational with whole, numerator, and denominator,
          denominator defaults to 1'''
          if denom == 0:
               raise ZeroDivisionError("The denominator cannot be zero.")
          self.numer = numer
          self.denom = denom
          self.whole = whole
          #print(self)

     def __str__(self):
          ''' String representation for printing '''
          if self.whole == 0:
               if self.denom == 1:
                    return str(self.numer)
               else:
                    return str(self.numer)+"/"+str(self.denom)
          else:
               if self.denom == 1:
                    return str(self.numer + self.whole)
               else:
                    return str(self.whole)+"/"+str(self.numer)+"/"+str(self.denom)

     def __repr__(self):
          ''' Used in interpreter. Call __str__for now '''
          return self.__str__()

     def __add__(self, param):
          ''' Add two Rationals '''
          the_lcm = lcm(self.denom, param.denom)
          numerator_sum = (the_lcm * self.numer / self.denom) + \
                         (the_lcm * param.numer / param.denom)
          return Rational(int(numerator_sum), the_lcm, self.whole+param.whole).reduce_Rational()
     
     def reduce_Rational(self):
          ''' Return the reduced fractional value as a Rational. '''
          the_gcd = gcd(self.numer, self.denom)
          return Rational((self.numer//the_gcd)%self.denom, self.denom//the_gcd, self.whole+(self.numer//self.denom))

def main():
     # test a, d
     x = Rational(1)
     print("x is: ", x)
     # test a, d
     x = Rational(2,3)
     print("x is: ", x)
     # test a, d
     x = Rational(1, whole=2)
     print("x is: ", x)
     # test a, d
     x = Rational(whole=1, numer=1, denom=2)
     print("x is: ", x)     
     # test a, d
     x = Rational(2,3,1)
     print("x is: ", x)
     # test c, d
     x = Rational(1,2,3)
     y = Rational(3,2,1)
     print("x+y =", x+y)
     # test c, d
     x = Rational(1,2)
     y = Rational(3,2,1)
     print("x+y =", x+y)
     # test c, d
     x = Rational(1)
     y = Rational(3,2,1)
     print("x+y =", x+y)
     # test c, d
     x = Rational(numer=0, whole=1)
     y = Rational(3,2,1)
     print("x+y =", x+y)
     # test c, d
     x = Rational(numer=5, denom=3, whole=1)
     y = Rational(3,2,1)
     print("x+y =", x+y)

     
main()
     
