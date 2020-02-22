a = gets.chomp.split.map(&:to_i).sort
puts a[2] - a[0]