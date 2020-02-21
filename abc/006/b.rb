n = gets.chomp.to_i
dp = [0] * (n + 1)
dp[3] = 1

4.upto(n) do |i|
  dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 10007
end

puts dp[n]