n = gets.chomp.to_i
an = gets.chomp.split.map(&:to_i)
ans = []
an.each.with_index(1) do |ai, i|
  ans[ai - 1] = i
end
puts ans.join(' ')