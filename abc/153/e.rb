h, n = gets.chomp.split.map(&:to_i)
dp = [0xffffffff] * (20001)
dp[0] = 0

n.times do
  a, b = gets.chomp.split.map(&:to_i)
  h.times do |i|
    x, y = a + i, b + dp[i]
    dp[x] = y if y < dp[x]
  end
end

puts dp.drop(h).min
