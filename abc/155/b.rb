n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

ans = true
a.each do |ai|
  next if ai.odd?

  if ai % 3 != 0 && ai % 5 != 0
    puts "DENIED"
    exit
  end
end

puts "APPROVED"