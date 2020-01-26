h, n = gets.split.map(&:to_i)
ary = Array.new(20001, 0xffffffff)
ary[0] = 0

n.times do
    a, b = gets.split.map(&:to_i)
    
    h.times do |i|
        x, y = ary[i + a], ary[i] + b
        ary[i + a] = y if y < x
    end
end

puts ary.drop(h).min
