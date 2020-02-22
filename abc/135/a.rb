# a - k = -b + k
# -2k = -b-a
# 2k = a+b
# k = (a+b)/2

# -a + k = b - k
# k = (a+b)/2

a, b = gets.chomp.split.map(&:to_i)
if (a + b).even?
  puts (a + b) / 2
else
  puts 'IMPOSSIBLE'
end