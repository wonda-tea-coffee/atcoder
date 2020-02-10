N, M = gets.split.map(&:to_i)
edge_list = M.times.map { gets.split.map(&:to_i) }
indegree = Array.new(N, 0)
graph = Array.new(N) { [] }
edge_list.each do |(u, v)|
  u -= 1
  v -= 1
  graph[u].push(v)
  indegree[v] += 1
end
zero_vertex_list = []
indegree.each.with_index do |c, i|
  zero_vertex_list.push(i) if c == 0
end

def next_edges(vertex_list, graph, indegree)
  ret = []
  vertex_list.each do |u|
    graph[u].each do |v|
      indegree[v] -= 1
      ret.push(v) if indegree[v] == 0
    end
  end
  ret
end

ans = 0
while !zero_vertex_list.empty?
  ans += 1
  zero_vertex_list = next_edges(zero_vertex_list, graph, indegree)
end
ans -= 1
puts ans