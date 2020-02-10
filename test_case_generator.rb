n = (2..100).to_a.sample
k = (1..100).to_a.sample

puts "#{n} #{k}"
h = []
n.times do
  h << (1..10000).to_a.sample
end
puts h.map(&:to_s).join(' ')