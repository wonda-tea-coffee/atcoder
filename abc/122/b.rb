S = gets.chomp

$atgc = ["A", "T", "G", "C"].freeze

def atgc?(s)
  len = s.length
  (0..(len-1)).each { |i| return false unless $atgc.include?(s[i]) }
  true
end

max = 0
len = S.length

(0..(len-1)).each { |start_idx|
  (1..(len - start_idx)).each { |l|
    max = [max, l].max if atgc?(S.slice(start_idx, l))
  }
}

puts max