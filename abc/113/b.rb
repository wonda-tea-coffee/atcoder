N = gets.to_i
T, A = gets.chomp.split.map(&:to_f)
H = gets.chomp.split.map(&:to_f)

sub = 0xffffffff
ans = -1

H.each.with_index(1) do |hi, i|
  s = (A - (T - hi * 0.006)).abs
  if s < sub
    sub = s
    ans = i
  end
end

puts ans