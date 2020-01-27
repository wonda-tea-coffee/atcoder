class Integer
  # n^(-1) mod m
  # TODO: 要理解
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
