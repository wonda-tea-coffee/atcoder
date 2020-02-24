n = gets.to_i
v = gets.chomp.split.map(&:to_r).sort
while v.size > 1
  v1 = v.shift
  v2 = v.shift
  v << (v1 + v2) / 2
  v.sort!
end
puts v[0].to_f