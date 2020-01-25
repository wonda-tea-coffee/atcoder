n = gets.chomp.to_i
s = gets.chomp
alp = (97..122).to_a.map(&:chr).map(&:upcase)

ans = ''
s.size.times do |i|
  ans << alp[(alp.index(s[i]) + n) % 26]
end
puts ans
