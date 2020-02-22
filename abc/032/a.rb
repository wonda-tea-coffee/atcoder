a = gets.to_i
b = gets.to_i
n = gets.to_i
l = a.lcm(b)
puts n + (-n % l)