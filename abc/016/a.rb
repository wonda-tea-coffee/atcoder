m, d = gets.chomp.split.map(&:to_i)
puts m % d == 0 ? 'YES' : 'NO'