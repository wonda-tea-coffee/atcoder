n = gets.chomp.to_i

ng = []
ng << gets.chomp.to_i
ng << gets.chomp.to_i
ng << gets.chomp.to_i

if ng.include?(n)
  puts "NO"
  exit
end

max = 300
INF = 0xffffffff
dp = [INF] * (max + 1)
dp[n] = 0

1.upto(3) do |i|
  if !ng.include?(n - i)
    dp[n - i] = 1
  end

  n.downto(0) do |j|
    next if dp[j] == INF
    break if j < i
    next if ng.include?(j - i)
    dp[j - i] = [dp[j - i], dp[j] + 1].min
  end
end

p dp

if dp[n] > 100
  puts "NO"
else
  puts "YES"
end