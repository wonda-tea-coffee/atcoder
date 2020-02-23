n = gets.to_i
a = gets.chomp.split.map(&:to_i)
lcm = a.inject(&:lcm)

b = 0
a.each do |ai|
  b += lcm / ai
end
puts lcm / b.to_f