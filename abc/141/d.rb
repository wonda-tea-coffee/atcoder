# 10^5回、要素数10^9の配列のソートをする
n, m = gets.chomp.split.map(&:to_i)
an = gets.chomp.split.map(&:to_i)

m.times do
  an.sort!
  an[-1] /= 2
end

puts an.inject(&:+)
