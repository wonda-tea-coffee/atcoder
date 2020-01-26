weathers = %w(Sunny Cloudy Rainy)
s = gets.chomp
i = weathers.index(s)
puts weathers[(i + 1) % 3]