H, W = gets.split.map(&:to_i)
M = H.times.map{gets.chomp}
G = Array.new(H * W) { [] }
W.times.each_cons(2) do |x1,x2|
  H.times do |y|
    if M[y][x1] == '.' && M[y][x2] == '.'
      G[y * W + x1] << y * W + x2
      G[y * W + x2] << y * W + x1
    end
  end
end
H.times.each_cons(2) do |y1,y2|
  W.times do |x|
    if M[y1][x] == '.' && M[y2][x] == '.'
      G[y1 * W + x] << y2 * W + x
      G[y2 * W + x] << y1 * W + x
    end
  end
end

def bfs(s)
  used = Array.new(H * W)
  q = [s]
  used[s] = 0
  until q.empty?
    u = q.shift
    G[u].each do |v|
      if !used[v]
        used[v] = used[u] + 1
        q << v
      end
    end
  end
  used.compact.max
end

puts (H * W).times.map{|s| bfs(s)}.max
