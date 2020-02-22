x, y = gets.chomp.split.map(&:to_i)
puts x > y ? 'Worse' : 'Better'