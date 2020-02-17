N, K = gets.chomp.split.map(&:to_i)
A = gets.chomp.split.map(&:to_i)

# 負の数
nega = []
# 正の数
posi = []
# 0のカウンタ
zeros = 0

# Aの数をnega, posiに分配 & 0の数を数える
A.each do |ai|
  if ai < 0
    nega << ai
  elsif ai > 0
    posi << ai
  else
    zeros += 1
  end
end

# 正の数は昇順にソート
posi.sort!
# 負の数は降順にソート
nega.sort!.reverse!

# A_iの値の制約の最小値（最大値）同士の積よりわずかに小さい（大きい）値を設定する
ng = -(10 ** 18) - 1
ok = 10 ** 18 + 1

# 二分探索で「積がx以下になるペアの総数が、k以上であるようなxの最小値」を求める
while ok - ng > 1
  mid = (ok + ng) / 2
  cnt = 0

  if mid >= 0
    # 積が0になるペア数を加算
    # (0同士のペア + 0と0でない数のペア)
    cnt += zeros * (zeros - 1) / 2 + zeros * (N - zeros)
  end

  if mid > 0
    # 何もわからない
    cnt += nega.size * posi.size

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
    r = nega.size - 1
    0.upto(posi.size - 1) do |l|
      while r >= 0 && posi[l] * nega[r] <= mid
        r -= 1
      end
      cnt += nega.size - r - 1
    end
  end

  if cnt >= K
    ok = mid
  else
    ng = mid
  end
end
puts ok