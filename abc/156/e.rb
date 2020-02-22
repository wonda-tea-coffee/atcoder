def min(a, b)
  a < b ? a : b
end

s = gets.chomp.reverse! + '0'
n = s.size
dp = Array.new(1000005){ Array.new(2) }
0.upto(n) do |i|
  0.upto(1) do |j|
    dp[i][j] = 0xffffffff
  end
end
dp[0][0] = 0

0.upto(n - 1) do |i|
  0.upto(1) do |j|
    x = s[i].to_i
    x += j
    0.upto(9) do |a|
      ni = i + 1
      nj = 0
      b = a - x
      if b < 0
        nj = 1
        b += 10
      end
      dp[ni][nj] = min(dp[ni][nj], dp[i][j] + a + b)
    end
  end
end

puts dp[n][0]