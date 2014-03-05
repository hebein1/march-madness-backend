File.open('ncaaTest.data', 'w') do |file|
	i = 0
	str = "2000 2 1\n"
	while i<2000 do
		pair = ""
		rand1 = Random.rand(50...80)
		pair += rand1.to_s + " "
		rand2 = Random.rand(50...80)
		pair += rand2.to_s + "\n"
		
		if rand1 >= rand2
			pair += 1.to_s + "\n"
		else
			pair += 0.to_s + "\n"
		end
		
		str += pair

		i += 1

	end

	file.write(str)
end
 
