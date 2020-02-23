n = gets.to_i
a = gets.chomp.split.map(&:to_i)
sorted = a.sort
diff = 0
a.each.with_index do |ai, i|
  if ai != sorted[i]
    diff += 1
  end
end
puts diff <= 2 ? 'YES' : 'NO'