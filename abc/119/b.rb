N = gets.to_i

ans = 0
N.times {
  x, u = gets.chomp.split

  ans += u == 'JPY' ? x.to_i : (x.to_f * 380000)
}

puts ans