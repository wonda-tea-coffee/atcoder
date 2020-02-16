n, k = gets.chomp.split.map(&:to_i)
s = gets.chomp
ans = ''
s.chars.each.with_index(1) do |si, i|
  if i == k
    ans += si.downcase
  else
    ans += si
  end
end
puts ans