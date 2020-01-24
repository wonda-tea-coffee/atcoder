N, K, M = gets.chomp.split.map(&:to_i)
scores = gets.chomp.split.map(&:to_i)
x = M * N - scores.inject(&:+)
puts x > K ? -1 : [x, 0].max
