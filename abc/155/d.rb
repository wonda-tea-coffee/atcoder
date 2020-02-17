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
    # 負数になるペア数を加算
    cnt += nega.size * posi.size

    # 正の数の配列、負の数の配列それぞれに対して、
    # ある数を固定したときに、それとペアになりうる数を足していく
    [posi, nega].each do |a|
      l = 0
      r = a.size - 1
      while l < r
        while l < r && a[l] * a[r] > mid
          r -= 1
        end
        # ここに到達した時点で a[l] * a[r] <= mid
        # ex.)
        # 1. l = r ならばカウントされない
        # 2. a[3] * a[6] <= mid ならば a[3] * a[4], a[3] * a[5], a[3] * a[6] で 6 - 3 = 3 がカウントされる
        cnt += r - l
        l += 1
      end
    end
  else
    # mid <= 0 の場合
    # posiは昇順、negaは降順に並んでいることに注意
    # （ex. posi = [1, 2, 3, ...], nega = [-1, -2, -3, ...]）
    r = nega.size - 1
    # posiのある要素を固定し、negaの要素と右から左（posi[l] * nega[r]は増大していく）へ順にペアを作っていく
    0.upto(posi.size - 1) do |l|
      while r >= 0 && posi[l] * nega[r] <= mid
        r -= 1
      end
      # ここに来た時点で、
      # r == -1 or posi[l] * nega[r] > mid
      # のいずれかが true になる
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