gets.chomp.chars.each_cons(3) do |a|
  if a.uniq.size == 1
    puts 'Yes'
    exit
  end
end
puts 'No'