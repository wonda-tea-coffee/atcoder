def min(a, b)
  a < b ? a : b
end

n = gets.to_i
x = gets.chomp.split.map(&:to_i)
ans = 0xffffffff

1.upto(x.max) do |p|
  cnt = 0
  x.each do |xi|
    cnt += (xi - p) ** 2
  end
  ans = min(ans, cnt)
end

puts ans