n = gets.to_i
h = gets.chomp.split.map(&:to_i).reverse
max = 0
len = 0
tmp = -0xffffffff
h.each.with_index do |hi, i|
  if hi >= tmp
    len += 1
  else
    max = [max, len].max
    len = 1
  end

  tmp = hi
end

puts [max, len].max - 1