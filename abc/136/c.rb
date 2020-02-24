n = gets.to_i
h = gets.chomp.split.map(&:to_i)

(n - 2).downto(0) do |i|
  if h[i] > h[i + 1]
    if h[i] == h[i + 1] + 1
      h[i] -= 1
    else
      puts 'No'
      exit
    end
  end
end

puts h == h.sort ? 'Yes' : 'No'