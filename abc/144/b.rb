b = []
(1..9).to_a.repeated_permutation(2) do |a|
  b << a[0] * a[1]
end
b.uniq!

n = gets.chomp.to_i
puts b.include?(n) ? 'Yes' : 'No'
