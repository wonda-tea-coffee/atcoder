n = gets.to_i
v = gets.chomp.split.map(&:to_i)
c = gets.chomp.split.map(&:to_i)

ans = 0
n.times do |i|
  w = v[i] - c[i]
  ans += w if w > 0
end
puts ans