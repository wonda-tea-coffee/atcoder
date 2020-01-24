a, b = gets.chomp.split

min = [a, b].min
max = [a, b].max

puts min * max.to_i
