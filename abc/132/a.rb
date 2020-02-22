s = gets.chomp.chars
h = Hash.new(0)
s.each do |si|
  h[si] += 1
end

puts h.values == [2, 2] ? 'Yes' : 'No'