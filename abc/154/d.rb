h = gets.chomp.to_i

@memo = {}
def solve(n)
  return 1 if n == 1
  return @memo[n] if @memo[n]

  m = (n/2.0).floor
  @memo[n] = 1 + solve(m)*2
end

puts solve(h)
