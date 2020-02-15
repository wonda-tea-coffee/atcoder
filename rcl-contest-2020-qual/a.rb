def next_put_pos(grid, c, v)
  
end

N, W, K, V = gets.chomp.split.map(&:to_i)
# 一番右端に置いたモノミノの数の合計を入れる
grid = Array.new(N){[] * (W + 1)}
N.times do |i|
  l = gets.chomp.split.map(&:to_i)
  c, v = l

  i, j = next_put_pos(grid, h, c, v)

  grid[i][j] = [c, v]

  puts j
end