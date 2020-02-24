n = gets.to_i
h = {}
ans = 0
n.times do
  s = gets.chomp.unpack("C*").sort!.pack("U*")
  if h[s]
    ans += h[s]
    h[s] += 1
  else
    h[s] = 1
  end
end
puts ans