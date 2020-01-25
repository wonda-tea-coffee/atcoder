a, b = gets.chomp.split.map(&:to_i)
puts a > 9 || b > 9 ? -1 : a*b