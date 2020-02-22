s = gets.chomp.split.map(&:to_i).sort.reverse
puts s[0] * 10 + s[1] + s[2]