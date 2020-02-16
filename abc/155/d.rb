n, k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)

nega = []
posi = []
zeros = 0

a.each do |ai|
  if ai < 0
    nega << ai
  elsif ai > 0
    posi << ai
  else
    zeros += 1
  end
end

posi.sort!
nega.sort!.reverse!

ng = - (10 ** 18) - 1
ok = 10 ** 18 + 1

while ok - ng > 1
  mid = (ok + ng) / 2
  cnt = 0

  if mid >= 0
    cnt += zeros * (zeros - 1) / 2 + zeros * (n - zeros)
  end

  if mid > 0
    cnt += nega.size * posi.size
    [posi, nega].each do |a|
      l = 0
      r = a.size - 1
      while l < r
        while l < r and a[l] * a[r] > mid
          r -= 1
        end
        cnt += r - l
        l += 1
      end
    end
  else
    r = nega.size - 1
    0.upto(posi.size - 1) do |l|
      while r >= 0 and posi[l] * nega[r] <= mid
        r -= 1
      end
      cnt += nega.size - r - 1
    end
  end

  if cnt >= k
    ok = mid
  else
    ng = mid
  end
end
puts ok