a, b = gets.chomp.split.map(&:to_i)
puts [a, b, a + b].any?{|x| x % 3 == 0} ? 'Possible' : 'Impossible'