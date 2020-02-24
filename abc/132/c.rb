N = gets.to_i
d = gets.chomp.split.map(&:to_i).sort

ans = 0
(d.min).upto(d.max) do |k|
  idx = d.bsearch_index{|x| x >= k}
  if idx == N / 2
    ans += 1
  elsif idx > N / 2
    break
  end
end
puts ans