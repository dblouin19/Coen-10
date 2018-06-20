<html>
<body>
	<p>Answer </p>
	<?php
	$name=$_POST["Guess"];
		$found=0;
		$value=array(0,0,0,0,0);
		for($i=0;$i<5;$i++)
			$value[$i]=rand(1,20);
		for($i=0;$i<5;$i++) {
				if($name==$value[$i])
					$found=1;
		}
		if ($found==1) {
			echo "Correct, all winning numbers were:";}
		else
			echo "Incorrect, winning numbers were:";
			for ($i=0;$i<5;$i++){
					echo "$value[$i] </br>"; }
	?>
	<form method="POST" action="lab3.html" >
	</form>
	</body>
	</html>
