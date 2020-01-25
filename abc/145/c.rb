def fact(n)
  return 1 if n <= 1
  n * fact(n-1)
end

def dist(point1, point2)
  x1 = point1[0]
  y1 = point1[1]
  x2 = point2[0]
  y2 = point2[1]

  Math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
end

n = gets.chomp.to_i
points = []
n.times do
  points << gets.chomp.split.map(&:to_i)
end
sum = 0.0
(0...n).to_a.permutation do |route|
  1.upto(n-1) do |i|
    sum += dist(points[route[i]], points[route[i-1]])
  end
end
puts sum / fact(n)