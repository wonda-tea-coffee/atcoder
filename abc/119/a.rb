_, m, _ = gets.chomp.split('/').map(&:to_i)

if m <= 4
  puts 'Heisei'
else
  puts 'TBD'
end