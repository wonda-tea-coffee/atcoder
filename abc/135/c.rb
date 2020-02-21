n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)

ans = 0
0.upto(n - 1) do |i|
  m1 = [a[i], b[i]].min
  a[i] -= m1
  b[i] -= m1

  m2 = [a[i + 1], b[i]].min
  a[i + 1] -= m2
  b[i] -= m2

  ans += m1 + m2
end
puts ans