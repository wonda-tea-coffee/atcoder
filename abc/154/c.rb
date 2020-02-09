gets
s = gets.chomp.split
puts s.size == s.uniq.size ? 'YES' : 'NO'