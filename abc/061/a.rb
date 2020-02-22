a, b, c = gets.chomp.split.map(&:to_i)
if a <= c && c <= b
  puts 'Yes'
else
  puts 'No'
end
