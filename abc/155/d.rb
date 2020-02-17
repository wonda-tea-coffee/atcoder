N, K = gets.chomp.split.map(&:to_i)
A = gets.chomp.split.map(&:to_i)

posi = []
nega = []
zeros = 0
A.each do |ai|
  if ai > 0
    posi << ai
  elsif ai < 0
    nega << ai
  else
    zeros += 1
  end
end

posi.sort!
nega.sort!.reverse!
posi_size = posi.size
nega_size = nega.size

ng = -(10**18 + 1)
ok = 10**18 + 1
while ok - ng > 1
  mid = (ok + ng) / 2
  cnt = 0

  if mid >= 0
    cnt += zeros * (zeros - 1) / 2 + zeros * (N - zeros)
  end

  if mid > 0
    cnt += posi_size * nega_size

    [posi, nega].each do |a|
      l = 0
      r = a.size - 1
      while l < r
        while l < r && a[l] * a[r] > mid
          r -= 1
        end
        cnt += r - l
        l += 1
      end
    end
  else
    r = nega_size - 1
    0.upto(posi_size - 1) do |l|
      while r >= 0 && posi[l] * nega[r] <= mid
        r -= 1
      end
      cnt += nega_size - r - 1
    end
  end

  if cnt >= K
    ok = mid
  else
    ng = mid
  end
end
puts ok