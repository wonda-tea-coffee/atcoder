n, m = gets.chomp.split.map(&:to_i)

a = (3*n-m..(4*n-m)/2).to_a.max
puts a.nil? || a < 0 ? "-1 -1 -1" : "#{a} #{4*n-m-2*a} #{a+m-3*n}"
