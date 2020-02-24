n = gets.to_i
p = []
n.times do
  p << gets.to_i
end
p.sort!
puts p.pop / 2 + p.inject(&:+)