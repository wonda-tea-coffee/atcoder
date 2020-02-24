W, H, x, y = gets.chomp.split.map(&:to_f)
puts "#{W * H / 2} #{W / 2 == x && H / 2 == y ? 1 : 0}"