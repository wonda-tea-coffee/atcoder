class Integer
  def modinv(m)
    a, b, i, j = self, m, 1, 0
    while b > 0
      t = a / b
      a, b = b, a - t * b
      i, j = j, i - t * j
    end
    i % m
  end
end

gets.chomp.to_i
an = gets.chomp.split.map(&:to_i)
m = (1e9 + 7).to_i
lcm = an.inject(:lcm) % m
sum = 0
an.each do |ai|
  sum += ai.modinv(m)
end
puts lcm * sum % m