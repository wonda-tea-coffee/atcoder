n, k = gets.chomp.split.map(&:to_i)

v = Math.log(n, k)

if v == v.to_i
  puts v.to_i + 1
else
  puts v.ceil.to_i
end