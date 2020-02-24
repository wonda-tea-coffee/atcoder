H, W = gets.chomp.split.map(&:to_i)
a = []
H.times do
  l = gets.chomp.chars
  a << l if l.include?('#')
end
a.transpose.select{|x| x.include?('#')}.transpose.each {|x| puts x.join}
