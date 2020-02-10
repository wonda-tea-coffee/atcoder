n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
dp = [0] * n
dp[1] = (a[1] - a[0]).abs
(2...n).to_a.each do |i|
  dp[i] = [dp[i - 1] + (a[i] - a[i - 1]).abs, dp[i - 2] + (a[i] - a[i - 2]).abs].min
end
puts dp[-1]