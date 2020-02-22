a = gets.to_i
b = gets.to_i
c = gets.to_i
d = [a, b, c].sort.reverse
puts d.index(a) + 1
puts d.index(b) + 1
puts d.index(c) + 1