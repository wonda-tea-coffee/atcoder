a = gets.chomp.split.map(&:to_i)

puts a.uniq.size == 2 ? 'Yes' : 'No'