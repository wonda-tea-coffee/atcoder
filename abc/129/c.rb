n, m = gets.chomp.split.map(&:to_i)
dp = [0] * (n + 1)

dp[0] = 1
dp[1] = 1

m.times do
  a = gets.to_i
  dp[a] = -1
end
mod = 10**9 + 7

2.upto(n) do |i|
  next if dp[i] == -1
  v1 = dp[i - 1] == -1 ? 0 : dp[i - 1]
  v2 = dp[i - 2] == -1 ? 0 : dp[i - 2]
  dp[i] = (v1 + v2) % mod
end

puts dp[n]