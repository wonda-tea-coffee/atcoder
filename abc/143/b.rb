n = gets.chomp.to_i
dn = gets.chomp.split.map(&:to_i)
sum = 0
dn.permutation(2) do |p|
  sum += p[0] * p[1]
end
puts sum / 2
