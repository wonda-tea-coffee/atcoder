gets
p = gets.chomp.split.map(&:to_i)

ans = 0

p.each_cons(3) do |a|
  mid = a[1]
  if a.sort.index(mid) == 1
    ans += 1
  end
end

puts ans