a, b = gets.chomp.split.map(&:to_i)
puts [a-2*b, 0].max
