gets.chomp.chars.each_cons(2) do |a, b|
  if a == b
    puts "Bad"
    exit
  end
end
puts "Good"