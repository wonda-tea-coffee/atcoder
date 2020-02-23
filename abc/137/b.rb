k, x = gets.chomp.split.map(&:to_i)
puts ([x - k + 1, -1_000_000].max..[x + k - 1, 1000000].min).to_a.map(&:to_s).join(' ')