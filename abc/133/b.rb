n, d = gets.chomp.split.map(&:to_i)
p = [] * n
n.times do
  p << gets.chomp.split.map(&:to_i)
end

ans = 0

0.upto(n - 1) do |i|
  (i + 1).upto(n - 1) do |j|
    dist = 0
    0.upto(d - 1) do |k|
      dist += (p[i][k] - p[j][k])**2
    end
    dist = dist ** 0.5

    if dist == dist.to_i
      ans += 1
    end
  end
end

puts ans