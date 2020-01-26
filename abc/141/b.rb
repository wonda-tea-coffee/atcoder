s = gets.chomp
flag = true
s.size.times do |i|
  flag = false if i % 2 == 0 && s[i] == 'L'
  flag = false if i % 2 == 1 && s[i] == 'R'
end
puts flag ? 'Yes' : 'No'