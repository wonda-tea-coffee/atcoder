# gets.chomp.split.map(&:to_i)
# gets.to_i
# gets.chomp
n, r = gets.chomp.split.map(&:to_i)
if n >= 10
  puts r
else
  puts r + 100 * (10 - n)
end