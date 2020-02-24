N = gets.to_i
b = gets.chomp.split.map(&:to_i)
ans = b[0] + b[-1]
b.each_cons(2) do |b1, b2|
  ans += [b1, b2].min
end
puts ans
