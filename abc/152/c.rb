gets
ary = gets.chomp.split.map(&:to_i)
ret = 0
min = ary[0]
ary.each.with_index(1) do |pi, i|
  next if pi > min

  min = pi
  ret += 1
end
puts ret
