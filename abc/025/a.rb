s = gets.chomp.chars
n = gets.to_i - 1
puts s[n / 5] + s[n % 5]