a, b, x = gets.chomp.split.map(&:to_i)
ans = 0
min = 1
max = 1e9.to_i
while min <= max do
  mid = (min + max) / 2
  if x >= a * mid + b * (Math.log10(mid).to_i + 1)
    ans = mid
    min = mid + 1
  else
    max = mid - 1
  end
end

puts ans
