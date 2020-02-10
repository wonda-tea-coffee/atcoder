s_orig = gets.chomp
t_orig = gets.chomp

s = s_orig.codepoints
t = t_orig.codepoints

s_size = s.size
t_size = t.size

dp = Array.new(s_size + 1) { Array.new(t_size + 1, 0) }

0.upto(s_size - 1).each do |i|
  dpi = dp[i]
  dpi1 = dp[i + 1]
  0.upto(t_size - 1).each do |j|
    if s[i] == t[j]
      dpi1[j + 1] = dpi[j] + 1
    else
      dpi1[j + 1] = dpi[j + 1] > dpi1[j] ? dpi[j + 1] : dpi1[j]
    end
  end
end

ans = ''
y = s_size
x = t_size

while y > 0
  if dp[y - 1][x] == dp[y][x]
    y -= 1
  elsif dp[y][x - 1] == dp[y][x]
    x -= 1
  else
    y -= 1
    x -= 1
    ans << s_orig[y]
  end
end

puts ans.reverse