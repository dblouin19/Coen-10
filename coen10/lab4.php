<html>
<body>
	
	<p>Winning Numbers: </p>
	
	<?php
	
	$Guess1=$_POST ["Guess1"];
	$Guess2=$_POST ["Guess2"];
	$Guess3=$_POST ["Guess3"];
	$Guess4=$_POST ["Guess4"];
	$Guess5=$_POST ["Guess5"];

		$user=array ($Guess1, $Guess2, $Guess3, $Guess4, $Guess5);
		$x=array(0,0,0,0,0);
		for ($i=0;$i<5;$i++)
		{
			$x[$i] = rand(0,20);
			for ($J = $i-1;$J>=0;$J--)
				if ($x[$i]==$x[$J])
				{ 
						$i--;
						break;
				}
		}
	$counter=0;
	for ($i=0;$i<5;$i++)
		for ($J=0;$J<5;$J++)
			{
				if ($x[$i]==$user[$J])
					$counter++;
			}
	echo "You got $counter right </br>";
	
	for ($i=0;$i<5;$i++)
		echo "$user[$i] ";
	echo "</br>";
	for ($i=0;$i<5;$i++)
		echo "$x[$i] ";

	
	?>

</body>
</html>
