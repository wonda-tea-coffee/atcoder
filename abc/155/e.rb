s = gets.chomp.chars.map(&:to_i)
c = [0, 1, 2, 3, 4, 5, 5, 4, 3, 2]

i = s.size - 1
while i > 0
  if s[i] > 6
    s[i] = 10 - s[i]
    s[i - 1] += 1
  end
  i -= 1
end
if s[0] > 6
  s[0] = 10 - s[0]
  s.unshift(1)
end

puts "i = #{i}"
p s.map(&:to_s).join.to_i

ans = 0
s.each do |si|
  ans += c[si]
end

puts ans