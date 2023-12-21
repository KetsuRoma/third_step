science_scores = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]
english_scores = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

# 1. それぞれの科目の平均,合計点を求める
english_sum = english_scores.sum.to_f
science_sum = science_scores.sum.to_f
science_avg = science_sum / science_scores.size
english_avg = english_sum / english_scores.size
puts "英語の合計点は#{english_sum}点"
puts "理科の合計点は#{science_sum}点"
puts "英語の平均点は#{english_avg}点"
puts "理科の平均点は#{science_avg}点"

#標準偏差を求める
science_standard_deviation = 0
english_standard_deviation = 0
science_scores.size.times do |i|
    science_standard_deviation += (science_scores[i]- science_avg)**2
    english_standard_deviation += (english_scores[i]- english_avg)**2
end
science_standard_deviation = Math.sqrt(science_standard_deviation/science_scores.size)
english_standard_deviation = Math.sqrt(english_standard_deviation/english_scores.size)
puts "理科の標準偏差は#{science_standard_deviation}点"
puts "英語の標準偏差は#{english_standard_deviation}点"

#偏差値を求める
science_scores.size.times do |i|
    puts "#{i+1}番"
    puts "理科の偏差値:#{(science_scores[i]- science_avg)/science_standard_deviation*10+50}"
    puts "英語の偏差値:#{(english_scores[i]- english_avg)/english_standard_deviation*10+50}"
end
#点数の高い順番に並べる
p science_scores.sort.reverse
p english_scores.sort.reverse
