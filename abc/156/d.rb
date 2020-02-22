class Integer
  def inverse(m)
    return Rational(1, self) if m.nil?

    a, b, u, v = self, m, 1, 0
    until b.zero?
        a, (t, b) = b, a.divmod(b)
        u, v = v, u - t * v
    end

    u = -u if a < 0
    u % m
  end
end

require 'openssl'

n, a, b = gets.chomp.split.map(&:to_i)
mod = 10**9 + 7

k = a > b ? a : b
cb = [] * (k + 1)
cb[0] = 1
1.upto(k) do |i|
  cb[i] = cb[i - 1] * (n - i + 1) * i.inverse(mod) % mod
end

puts (2.to_bn.mod_exp(n, mod).to_i - cb[a] - cb[b] - 1) % mod