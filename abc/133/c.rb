def min(a, b)
  a < b ? a : b
end

L, R = gets.chomp.split.map(&:to_i)

if R - L + 1 >= 2019
  puts 0
  exit
end

min = 0xffffffff
L.upto(R) do |i|
  (i + 1).upto(R) do |j|
    min = min(min, i * j % 2019)
  end
end
puts min