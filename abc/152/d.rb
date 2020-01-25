n = gets.chomp.to_i
@c = {}

1.upto(n) do |i|
  str_i = i.to_s
  key = [str_i[0], str_i[-1]]
  @c[key] ||= 0
  @c[key] += 1
end

sum = 0
(1..9).to_a.map(&:to_s).repeated_permutation(2) do |p|
  sum += @c[[p[0], p[1]]].to_i * @c[[p[1], p[0]]].to_i
end
puts sum
