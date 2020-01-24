n = gets.chomp.to_i
s, t = gets.chomp.split
o = ''
n.times do |i|
  o << s[i] + t[i]
end
puts o
