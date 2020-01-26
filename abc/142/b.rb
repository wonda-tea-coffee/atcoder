n, k = gets.chomp.split.map(&:to_i)
hn = gets.chomp.split.map(&:to_i)
cnt = 0
hn.each do |hi|
  cnt += 1 if hi >= k
end
puts cnt