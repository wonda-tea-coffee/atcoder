n = gets.to_i
w = gets.chomp.split.map(&:to_i)
all_sum = w.inject(&:+)
part_sum = 0
ans = 0xffffffff

0.upto(w.size - 2) do |i|
  part_sum += w[i]
  ans = [ans, (all_sum - 2 * part_sum).abs].min
end

puts ans