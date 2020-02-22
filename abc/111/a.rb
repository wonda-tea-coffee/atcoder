ans = ''
gets.chomp.chars.each do |c|
  if c == '1'
    ans << '9'
  elsif c == '9'
    ans << '1'
  else
    ans << c
  end
end
puts ans