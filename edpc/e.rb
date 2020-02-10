def min(a, b)
  a < b ? a : b
end

N, W = gets.chomp.split.map(&:to_i)
w = [] * N
v = [] * N
N.times do
  wi, vi = gets.chomp.split.map(&:to_i)
  w << wi
  v << vi
end

MAX_VALUE = v.inject(&:+) + 1
dp = Array.new(MAX_VALUE) { 0xffffffff }
dp[0] = 0

v.each.with_index do |vi, i|
  (MAX_VALUE-vi).downto(0) do |j|
    next if dp[j] == 0xffffffff

    dp[j + vi] = min(dp[j + vi], dp[j] + w[i])
  end
end

ans = 0
dp.each.with_index do |dpi, i|
  next if dpi > W
  ans = i
end

puts ans