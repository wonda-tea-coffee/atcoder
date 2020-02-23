n, l = gets.chomp.split.map(&:to_i)

x = -1
v = 0xfffffffff
1.upto(n) do |i|
  w = (l + i - 1).abs
  if w < v
    v = w
    x = i
  end
end

puts n * (n + 2 * l - 1) / 2 - (l + x - 1)