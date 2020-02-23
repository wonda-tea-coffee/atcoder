n = gets.to_i
d = n.to_s.size

if d.odd?
  puts (10 ** (d - 1) - 1) / 11 + (n - (10 ** (d - 1)) + 1)
else
  puts (10 ** d - 1) / 11
end
