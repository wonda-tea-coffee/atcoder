n = gets.chomp.to_i
pn = gets.chomp.split.map(&:to_i)
qn = gets.chomp.split.map(&:to_i)
a = b = -1
(1..n).to_a.permutation.each.with_index(1) do |p, i|
  a = i if p == pn
  b = i if p == qn
end
puts (a - b).abs
