n = gets.chomp.to_i
h = Hash.new(0)
n.times do
  h[gets.chomp] += 1
end

ans = []
max = 0
h.each do |k, v|
  if v > max
    max = v
    ans = [k]
  elsif v == max
    ans << k
  end
end

ans.sort.each do |si|
  puts si
end