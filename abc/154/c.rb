n, k = gets.chomp.split.map(&:to_i)
hn = gets.chomp.split.map(&:to_i).sort.reverse
ans = 0

if k >= n
  puts 0
  exit
end

k.times do |ki|
  hn[ki] = 0
end

puts hn.inject(&:+)
