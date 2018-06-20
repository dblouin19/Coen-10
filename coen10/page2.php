<html>
<Body align="center">
Joseph Sindelar

<p>
<?php

$number1 = $_POST["number1"];
$number2 = $_POST["number2"];
$number3 = $_POST["number3"];


//retrieve data from
//POST
if ($number1*$number2==$number3)
{ echo "Correct";
}
else {
echo "Incorrect $number1 x $number2 = "; echo $number1*$number2 ;
}
?>
<form method="POST" action="page1.php">
	<input type="submit" value="Try Another One" />
</p>
</body>
</form>
</html>
