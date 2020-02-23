gets
h = gets.chomp.split.map(&:to_i)
ans = 0
max = 0

h.each do |hi|
  ans += 1 if hi >= max
  max = [max, hi].max
end

puts ans