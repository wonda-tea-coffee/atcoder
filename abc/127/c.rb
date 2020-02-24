n, m = gets.chomp.split.map(&:to_i)
s = 1
e = n

m.times do
  l, r = gets.chomp.split.map(&:to_i)
  if l <= s && s <= r
    e = [e, r].min
  elsif l <= e && e <= r
    s = [s, l].max
  elsif s <= l && r <= e
    s = l
    e = r
  else
    e = s - 1
  end
end

puts e - s + 1