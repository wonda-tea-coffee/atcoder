a, b = gets.chomp.split.map(&:to_i)
a, b = b, a if a > b
puts a == b ? 2 * b : 2 * b - 1