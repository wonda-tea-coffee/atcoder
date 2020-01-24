a, b, k = gets.chomp.split.map(&:to_i)
if a > k
  puts "#{a - k} #{b}"
else
  k -= a
  puts b > k ? "0 #{b - k}" : "0 0"
end
