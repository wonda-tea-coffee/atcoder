l = gets.chomp.split.map(&:to_i).sort
puts 2 * (l[0] + l[-1]) - l.inject(&:+)