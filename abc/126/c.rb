n, k = gets.chomp.split.map(&:to_r)

sum = 0
1.upto([n, k - 1].min) do |i|
  sum += 2**(-Math.log(k / i, 2).ceil)
end
puts (sum / n).to_f + (n >= k ? 1 - (k - 1) / n : 0)