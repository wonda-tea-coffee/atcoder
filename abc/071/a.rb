x, a, b = gets.chomp.split.map(&:to_i)
d1 = (x - a).abs
d2 = (x - b).abs
if d1 < d2
  puts 'A'
else
  puts 'B'
end