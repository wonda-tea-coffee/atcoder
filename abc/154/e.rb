n = gets.chomp.to_i
k = gets.chomp.to_i

@memo = {}

def solve(n, k)
    return @memo[[n, k]] if @memo[[n, k]]
    return 1 if k == 0
    return 0 if n < 1
    return 0 if n.to_s.size < k

    head = n.to_s.chars[0].to_i
    c = n.to_s.chars
    c.shift
    right = c.join.to_i
    v = 10**c.size - 1

    v1 = solve(right, k - 1)
    v2 = (head - 1) * solve(v, k - 1)
    v3 = solve(v, k)

    @memo[[n, k]] = v1 + v2 + v3
end

puts solve(n, k)