a, b, c, k = gets.chomp.split.map(&:to_i)
s, t = gets.chomp.split.map(&:to_i)

p = s * a + t * b
if s + t >= k
  puts p - (s + t) * c
else
  puts p
end