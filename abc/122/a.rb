b = gets.chomp
puts b == "A" ? "T" : (b == "T" ? "A" : (b == "G" ? "C" : "G"))