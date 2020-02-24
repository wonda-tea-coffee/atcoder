# 1以上a以下の整数のうち、CでもDでも割り切れないものの数を求める
def solve(a, c, d)
  a - a / c - a / d + a / c.lcm(d)
end

A, B, C, D = gets.chomp.split.map(&:to_i)

puts solve(B, C, D) - solve(A - 1, C, D)