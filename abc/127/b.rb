r, d, x = gets.chomp.split.map(&:to_i)
10.times do
  v = r * x - d
  puts v
  x = v
end