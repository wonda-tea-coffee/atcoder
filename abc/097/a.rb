a, b, c, d = gets.chomp.split.map(&:to_i)
if (a - c).abs <= d
  puts 'Yes'
elsif (a - b).abs <= d && (b - c).abs <= d
  puts 'Yes'
else
  puts 'No'
end