n = gets.chomp.to_i
ans = []
n.times do |i|
  ai = gets.chomp.to_i
  ans[i] = []
  ai.times do
    x, y = gets.chomp.split.map(&:to_i)
    ans[i] << [x - 1, y == 1]
  end
end

[true, false].repeated_permutation(n) do |comb|
  catch :next_comb do
    n.times do |i|
      next unless comb[i]
      ans[i].each do |an|
        throw :next_comb unless comb[an[0]] == an[1]
      end
    end
    puts comb.count(true)
    exit
  end
end
