h, n = gets.chomp.split.map(&:to_i)
an = gets.chomp.split.map(&:to_i).sort.reverse
sum = 0
n.times do |ni|
  sum += an[ni]
end
puts sum >= h ? 'Yes' : 'No'
