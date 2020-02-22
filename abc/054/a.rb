a, b = gets.chomp.split.map(&:to_i)
c = ((2..13).to_a + [1])
d = c.index(a)
e = c.index(b)
if d > e
  puts 'Alice'
elsif d < e
  puts 'Bob'
else
  puts 'Draw'
end