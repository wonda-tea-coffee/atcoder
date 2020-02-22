n, s, t = gets.chomp.split.map(&:to_i)
w = gets.to_i
ans = 0
a = [0]
(n - 1).times do
  a << gets.to_i
end
a.each do |ai|
  if s <= w && w <= t
    ans += 1
  end

  w += ai
end
puts ans