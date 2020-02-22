x = gets.chomp.split.map(&:to_i)
if ([1, 3, 5, 7, 8, 10, 12] & x).size == 2
  puts 'Yes'
elsif ([4, 6, 9, 11] & x).size == 2
  puts 'Yes'
else
  puts 'No'
end