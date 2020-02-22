a = gets.chomp.split.map(&:to_r)
p = a[1] / a[0]
q = a[3] / a[2]
if p > q
  puts 'TAKAHASHI'
elsif p < q
  puts 'AOKI'
else
  puts 'DRAW'
end