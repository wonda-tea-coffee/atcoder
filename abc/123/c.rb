n = gets.chomp.to_r
a = []
5.times {a << gets.chomp.to_i}
puts (n / a.min).ceil + 4