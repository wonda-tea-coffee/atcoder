n, k = gets.chomp.split.map(&:to_i)
pn = gets.chomp.split.map(&:to_r)

sums = []*n
n.times do |i|
  sums[i] = (pn[i] + 1) / 2
end

sum = sums.take(k).inject(&:+)
head = 0
max = sum
(k...n).to_a.each do |i|
  max = [max, sum - sums[head] + sums[i]].max
  sum = sum - sums[head] + sums[i]
  head += 1
end
puts max.to_f