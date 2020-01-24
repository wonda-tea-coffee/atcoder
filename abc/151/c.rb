N, M = gets.chomp.split.map(&:to_i)
is_ac = {}
wa_cnts = {}
cnt_ac = cnt_pn = 0
M.times do
  pi, si = gets.chomp.split

  next if is_ac[pi]

  if si == 'AC'
    is_ac[pi] = true
    cnt_ac += 1
    cnt_pn += wa_cnts[pi] || 0
  else
    wa_cnts[pi] ||= 0
    wa_cnts[pi] += 1
  end
end
puts "#{cnt_ac} #{cnt_pn}"
