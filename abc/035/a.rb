w, h = gets.chomp.split.map(&:to_i)
if w / 4 * 3 == h
  puts "4:3"
else
  puts "16:9"
end