a = gets.chomp.split.map(&:to_i).sort
puts (a[0] + 1) * a[1]