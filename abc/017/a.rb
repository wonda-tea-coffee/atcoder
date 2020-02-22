r = []
3.times { r << gets.chomp.split.map(&:to_i) }
puts r.map{|ri| ri[0] * ri[1] / 10}.inject(&:+)