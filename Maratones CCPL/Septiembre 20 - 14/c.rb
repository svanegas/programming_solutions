/ For solve this problem the Catalan Numbers
  are used, to find the nth Catalan Number 
  you need to use the formula:
  Cn = (2*n)! \ ((n+1)!*n!)
  And you we have to find all possibilities,
  which are found by the Cn number times n!
  that is:
  ans = (2*n)! \ (n+1)!
  We get it by cancelling n!
  Now, you can reduce it by cancelling the firsts
  n + 1 terms, so the answer will be the product
  of the n+2 to 2*n elements. /
class ProbC
  def initialize
    @fact = Array.new(605)
  end
  def solve
    n = gets.chomp.to_i
    while n != 0
      ans = 1
      for i in (n+2..n*2)
        ans *= i
      end
      puts ans
      n = gets.chomp.to_i
    end
  end
end

obj = ProbC.new
obj.solve