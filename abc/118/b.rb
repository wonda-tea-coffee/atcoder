n, m = gets.chomp.split.map(&:to_i)
foods = (1..m).to_a

n.times do |i|
  l = gets.chomp.split.map(&:to_i)
  l.shift

  foods &= l
end

puts foods.size