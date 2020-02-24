s = gets.to_i
m = []

while true
  if m.include?(s)
    puts m.size + 1
    exit
  else
    m << s
  end

  s = s.even? ? s / 2 : 3 * s + 1
end