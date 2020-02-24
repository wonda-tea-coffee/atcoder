N = gets.to_i
w0 = gets.chomp
ans = true
h = {}
h[w0] = true
(N - 1).times do
  w1 = gets.chomp

  if w0[-1] != w1[0] || h[w1]
    ans = false
  end

  h[w1] = true
  w0 = w1
end
puts ans ? 'Yes' : 'No'