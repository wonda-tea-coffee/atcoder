n, m = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i).sort!

m.times do
  b, c = gets.chomp.split.map(&:to_i)

  cnt = 0
  while cnt < b && a[0] < c
    a.shift
    cnt += 1
  end
  # cnt回、cを適切な位置に挿入する
  idx = a.bsearch_index{|x| x >= c}
  if idx.nil?
    cnt.times { a << c }
  else
    cnt.times { a.insert(idx, c) }
  end
end
puts a.inject(&:+)