n, k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)

# 方針①：すべての組み合わせを高速に列挙する
# 最悪20,000,100,000個
#
# 方針②：何らかの方法で1番目,2番目,...,k番目と決めていく
# やはり最悪k = 20,000,100,000なので厳しい
#
# 方針③：他を知らずにk番目だけをピンポイントで求める

ps = []
ng = []
a.each do |ai|
  if ai < 0
    ng << ai
  else
    ps << ai
  end
end