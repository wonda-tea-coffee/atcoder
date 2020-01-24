require 'prime'

x = gets.chomp.to_i

loop do
  if Prime.instance.prime?(x)
    puts x
    exit
  end
  x += 1
end