A = gets.to_i
B = gets.to_i
C = gets.to_i
D = gets.to_i
E = gets.to_i

def solve(a, b, c, d, e)
  a + (10 - a % 10) % 10 + b + (10 - b % 10) % 10 + c + (10 - c % 10) % 10 + d + (10 - d % 10) % 10 + e
end

min = 1000

[A, B, C, D, E].permutation(5) { |a, b, c, d, e|
  min = [min, solve(a, b, c, d, e)].min
}

puts min