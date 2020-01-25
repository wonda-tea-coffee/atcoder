n = gets.chomp.to_i
s = Math.sqrt(n).to_i
s.downto(1) do |d|
  next if n % d > 0
  puts d-1 + n/d-1
  exit
end
