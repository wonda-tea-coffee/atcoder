s = gets.chomp
len = s.size
ans = 0
(len/2).times {|i|ans += 1 if s[i] != s[len-i-1]}
puts ans