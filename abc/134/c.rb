n = gets.to_i
a = []
n.times do
  a << gets.to_i
end

b = a.sort
max0 = b[-2]
max1 = b[-1]

a.each do |a|
  if a == max1
    puts max0
  else
    puts max1
  end
end