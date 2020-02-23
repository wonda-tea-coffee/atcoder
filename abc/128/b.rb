n = gets.to_i
rests = []
n.times do |i|
  s, p = gets.chomp.split
  p = p.to_i

  rests << [i + 1, s, p]
end

rests.sort! do |a, b|
  if a[1] < b[1]
    -1
  elsif a[1] > b[1]
    1
  elsif a[2] > b[2]
    -1
  else
    1
  end
end

rests.each do |rest|
  puts rest[0]
end
