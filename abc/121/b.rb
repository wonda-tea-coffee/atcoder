N, M, C = gets.split.map(&:to_i)

bm = gets.split.map(&:to_i)

ans = 0
N.times {
  am = gets.split.map(&:to_i)
  sum = 0
  (0..(M-1)).each { |i| sum += am[i] * bm[i] }
  ans += 1 if sum + C > 0
}

puts ans