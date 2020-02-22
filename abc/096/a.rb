a, b = gets.chomp.split.map(&:to_i)
ans = a - 1
ans += 1 if b >= a
puts ans