n = gets.chomp.to_i
a = [] * n
b = [] * n
c = [] * n
n.times do
  ai, bi, ci = gets.chomp.split.map(&:to_i)
  a << ai
  b << bi
  c << ci
end
dp = Array.new(n){Array.new(3){ 0 }}
max = [a[0], b[0], c[0]].max
3.times {|i| dp[0][i] = max }

(1...n).to_a.each do |i|
  v0 = dp[i - 1][0] > dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1]
  v1 = dp[i - 1][1] > dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]
  v2 = dp[i - 1][2] > dp[i - 1][0] ? dp[i - 1][2] : dp[i - 1][0]

  dp[i][0] = v1 + a[i]
  dp[i][1] = v2 + b[i]
  dp[i][2] = v0 + c[i]
end

puts [dp[-1][0], dp[-1][1], dp[-1][2]].max