N, T = gets.chomp.split.map(&:to_i)
INF = 0xffffffff
ans = INF
N.times do
  c, t = gets.chomp.split.map(&:to_i)

  next if t > T

  ans = [ans, c].min
end
puts ans == INF ? 'TLE' : ans