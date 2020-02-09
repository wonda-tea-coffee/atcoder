r1, c1, r2, c2 = gets.chomp.split.map(&:to_i)
m = [r1, r2].max
n = [c1, c2].max
dp = Array.new(m + 1){Array.new(n + 1){0}}

(0..m).to_a.each do |i|
  dp[i][0] = 1
end
(0..n).to_a.each do |i|
  dp[0][i] = 1
end

