A, B, K = gets.split.map(&:to_i)

cnt = 0
n = 100
while n >= 1
  if A % n == 0 && B % n == 0
    cnt += 1
    if cnt == K
      puts n
      exit
    end
  end

  n -= 1
end