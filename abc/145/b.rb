n = gets.chomp.to_i
s = gets.chomp
puts n.even? && (s[0,n/2] == s[n/2,n/2]) ? 'Yes' : 'No'