N = gets.to_i
r = (1..9).to_a.map{|x| x * 111}
r.each do |ri|
  if N <= ri
    puts ri
    exit
  end
end