s = gets.chomp.chars
t = gets.chomp

ans = 0
s.each.with_index do |si, i|
  ans += 1 if si == t[i]
end
puts ans