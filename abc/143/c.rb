n = gets.chomp.to_i
s = gets.chomp
i = 1
while i < s.size
  if s[i-1] != s[i]
    i +=1
    next
  end

  s.gsub!(s[i]*2, s[i])
end
puts s.size