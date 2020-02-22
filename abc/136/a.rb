a, b, c = gets.chomp.split.map(&:to_i)
puts c - [a - b, c].min