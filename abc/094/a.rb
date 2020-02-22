a, b, x = gets.chomp.split.map(&:to_i)

if x < a || a + b < x
  puts 'NO'
else
  puts 'YES'
end