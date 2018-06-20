<html>
<body align="center">
Multiplication Table
<?php 
$number1=rand(0,12);
$number2=rand(0,12);
echo "<p>$number1 x $number2 = ?</p>";
?>
<form method ="POST" action ="page2.php";>
<input type="hidden" name ="number1" value="<?php echo $number1;?>" />
<input type="hidden" name ="number2" value="<?php echo $number2;?>" />
<input type= "number" name="number3" />
<input type= "submit" value="Calculate!" />

</form>
</body>
</html>
