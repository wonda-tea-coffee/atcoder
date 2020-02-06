n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)
c = gets.chomp.split.map(&:to_i)
ans = 0
mae = 0xffffffff
n.times do |i|
  ai = a[i] - 1
  ans += b[ai]
  if mae + 1 == ai
    ans += c[mae]
  end

  mae = ai
end
puts ans