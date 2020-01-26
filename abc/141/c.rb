n, k, q = gets.chomp.split.map(&:to_i)
scores = [k]*n
ac = [0]*n
q.times do
  ai = gets.chomp.to_i
  ac[ai - 1] += 1
end

ac.each.with_index do |aci, i|
  scores[i] -= q - aci
end

scores.each do |s|
  puts s > 0 ? 'Yes' : 'No'
end
