gets
l = gets.chomp.split.map(&:to_i).sort
max = l.pop
if max < l.inject(&:+)
  puts 'Yes'
else
  puts 'No'
end