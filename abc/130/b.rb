n, x = gets.chomp.split.map(&:to_i)
l = gets.chomp.split.map(&:to_i)

ans = 0
p = 0
l.unshift(0)
l.each do |li|
  p += li
  ans += 1 if p <= x
end

puts ans