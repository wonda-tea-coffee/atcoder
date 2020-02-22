n = gets.to_i
case n
when 100
  puts 'Perfect'
when 90..99
  puts 'Great'
when 60..89
  puts 'Good'
when 0..59
  puts 'Bad'
end