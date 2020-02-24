N, M, X, Y = gets.chomp.split.map(&:to_i)
x = gets.chomp.split.map(&:to_i).sort
y = gets.chomp.split.map(&:to_i).sort

l = x[-1] + 1
r = y[0]

if ((l..r).to_a & (X+1..Y).to_a).size > 0
  puts 'No War'
else
  puts 'War'
end