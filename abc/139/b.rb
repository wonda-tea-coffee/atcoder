a, b = gets.chomp.split.map(&:to_r)
puts ((b - 1) / (a - 1)).ceil.to_i