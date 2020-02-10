# gets.chomp
# gets.chomp.to_i
# gets.chomp.split
# gets.chomp.split.map(&:to_i)

def max(a, b)
  a > b ? a : b
end

n, W = gets.chomp.split.map(&:to_i)
dp = Array.new(W + 1) { -1 }
dp[0] = 0
w = [] * n
v = [] * n
n.times do
  wi, vi = gets.chomp.split.map(&:to_i)
  w << wi
  v << vi
end

w.each.with_index do |wi, i|
  (W-wi).downto(0) do |j|
    next if dp[j] == -1

    dp[j + wi] = max(dp[j + wi], dp[j] + v[i])
  end
end

puts dp.max