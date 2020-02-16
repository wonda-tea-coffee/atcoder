s = gets.chomp
left = s.slice(0, 2).to_i
right = s.slice(2, 2).to_i
f1 = 1 <= left && left <= 12
f2 = 1 <= right && right <= 12

if f1 && f2
  puts "AMBIGUOUS"
elsif f1 && !f2
  puts "MMYY"
elsif !f1 && f2
  puts "YYMM"
else
  puts "NA"
end