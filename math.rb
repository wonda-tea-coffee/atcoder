# TODO: 要理解
# 組み合わせ個数
def choose(n, r, mod)
  return 0 if not (0 <= r and r <= n)
  return 1 if r == 0 or r == n
  fact2(n, r, mod) * inverse(fact(r, mod) % mod, mod) % mod
end

# TODO: 要理解
# 階乗(MODあり)
@fact = [1]
def fact(n, mod)
  if n > @fact.size then
    f = @fact[-1]
    (@fact.size+1..n).each{|i|
      f = (f * i) % mod
      @fact << f
    }
  end
  @fact[n-1]
end

# TODO: 要理解
def fact2(n, r, mod)
  f = 1
  n.downto(n-r+1){|i|
    f = (f * i) % mod
  }
  f
end

# TODO: 要理解
# 逆元(MODあり)
def inverse(x, mod)
  pow(x, mod-2, mod)
end

# TODO: 要理解
# べき乗(MODあり)(繰り返し２乗法)
def pow(x, n, mod)
  ans = 1
  while n > 0
    ans = ans * x % mod if n.odd?
    x = x * x % mod
    n >>= 1
  end
  ans
end
