_, g, b = gets.chomp.split.map(&:to_i)
puts (10 * g + b) % 4 == 0 ? 'YES' : 'NO'