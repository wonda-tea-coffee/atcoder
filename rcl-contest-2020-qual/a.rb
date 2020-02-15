N, W, K, V = gets.chomp.split.map(&:to_i)
N.times do |i|
  gets
  puts (0...W).to_a.sample
end