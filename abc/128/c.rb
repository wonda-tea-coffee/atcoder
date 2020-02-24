n, m = gets.chomp.split.map(&:to_i)
s = []
m.times do
  l = gets.chomp.split.map(&:to_i)
  l.shift
  s << l
end
p = gets.chomp.split.map(&:to_i)

ans = 0
0.upto((1 << n) - 1) do |i|
  flag = true
  0.upto(m - 1) do |j|
    cnt = 0

    s[j].each do |sj_k|
      if i & (1 << (sj_k - 1)) > 0
        cnt += 1
      end
    end

    if cnt % 2 != p[j]
      flag = false
      break
    end
  end

  ans += 1 if flag
end
puts ans