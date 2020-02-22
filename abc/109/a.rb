a, b = gets.chomp.split.map(&:to_i)
if a.even? || b.even?
  puts 'No'
else
  puts 'Yes'
end