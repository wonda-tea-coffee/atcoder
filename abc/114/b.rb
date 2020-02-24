s = gets.chomp.chars.map(&:to_i)
ans = 0xffffffff
s.each_cons(3) do |s1, s2, s3|
  ans = [ans, (753 - (s1 * 100 + s2 * 10 + s3)).abs].min
end
puts ans